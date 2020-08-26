/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 12:24:12 by julnolle          #+#    #+#             */
/*   Updated: 2020/08/26 17:45:37 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void *thread_philo(void *arg)
{
	t_data	*data;
	int		id;
	int		right;
	int		left;

	// printf("Nous sommes dans le thread %d.\n", data->selected_philo - 1);
	data = (t_data *)arg;
	memset(&id, 0, sizeof(int));
	id = data->selected_philo;
	right = id - 1;
	left = (right + 1) > data->nb - 1 ? 0 : (right + 1);

	while (1 && (get_time_in_ms(data->start_time) - data->last_meal_time[id - 1] < data->die_t))
	{

		if (pthread_mutex_lock(&data->fork[right]) != 0)
			ft_putendl("mutex lock failed");
		ft_print_state(get_time_in_ms(data->start_time), id, "has taken right fork", data);
		// printf("%6ld ms: Philo [%d] has taken right fork [%d]\n", get_time_in_ms(data->start_time), id, right);
		if (pthread_mutex_lock(&data->fork[left]) != 0)
			ft_putendl("mutex lock failed");
		ft_print_state(get_time_in_ms(data->start_time), id, "has taken left fork", data);
		// printf("%6ld ms: Philo [%d] has taken left fork [%d]\n", get_time_in_ms(data->start_time), id, left);
		ft_eat(id, data);
		if (pthread_mutex_unlock(&data->fork[right]) != 0)
			ft_putendl("mutex unlock failed");
		ft_print_state(get_time_in_ms(data->start_time), id, "released right fork", data);
		// printf("%6ld ms: Philo [%d] released right fork [%d]\n", get_time_in_ms(data->start_time), id, right);
		if (pthread_mutex_unlock(&data->fork[left]) != 0)
			ft_putendl("mutex unlock failed");
		ft_print_state(get_time_in_ms(data->start_time), id, "released left fork", data);
		// printf("%6ld ms: Philo [%d] released left fork [%d]\n", get_time_in_ms(data->start_time), id, left);
		// printf("last_meal_time of philo %d: %ldms\n", id, data->last_meal_time[id - 1]);
		ft_sleep(id, data);
		ft_think(id, data);
	}
	return (&data->last_meal_time[id - 1]);
}

int	 philo_one(t_data *data)
{
	pthread_t	thread[data->nb - 1];
	int			i;
	int			*thread_return;

	thread_return = NULL;
	if (pthread_mutex_init(&data->display, NULL) != 0)
	{
		ft_putendl("mutex init failed");
		return (FAILURE);
	}
	i = 0;
	while (i < data->nb)
	{
		if (pthread_mutex_init(&data->fork[i], NULL) != 0)
		{
			ft_putendl("mutex init failed");
			return (FAILURE);
		}
		
		i++;
	}
	i = 0;
	while (i < data->nb)
	{
		// pthread_mutex_init(&data->fork[i], NULL);
		// printf("creating thread %d\n", i);
		data->selected_philo = i + 1;
		if (pthread_create(&thread[i], NULL, thread_philo, data))
		{
			ft_putendl("pthread_create failed");
			return (FAILURE);
		}
		usleep(500);
		i++;
	}
	i = 0;
	while (i < data->nb)
	{
		if (pthread_join(thread[i], (void **)&thread_return))
		{
			ft_putendl("pthread_join failed");
			return (FAILURE);
		}
		ft_print_state(get_time_in_ms(data->start_time), i + 1, "is dead", data);
		// printf("The Philosopher [%d] died at %ldms, last meal at: %d\n", data->selected_philo, get_time_in_ms(data->start_time), *thread_return);
		return (FAILURE);
		i++;
	}
	i = 0;	
	while (i < data->nb)
	{
		if (pthread_mutex_destroy(&data->fork[i]) != 0)
		{
			ft_putendl("mutex destroy failed");
			return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}

int		main(int ac, char const **av)
{
	t_data	data;

	if (ac == 5 || ac == 6)
	{
		if (ft_init(&data, av, ac) == SUCCESS)
		{
			print_args(av);
			philo_one(&data);
		}
		else
			ft_putendl("Wrong number_of_philosopher");
	}
	else
		ft_putendl("Wrong nbr of arguments");
	return (0);
}
