/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 12:24:12 by julnolle          #+#    #+#             */
/*   Updated: 2020/10/06 17:52:05 by julnolle         ###   ########.fr       */
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
	// memset(&id, 0, sizeof(int));
	// memset(&right, 0, sizeof(int));
	// memset(&left, 0, sizeof(int));
	id = data->selected_philo;
	right = id - 1;
	left = (right + 1) > data->nb - 1 ? 0 : (right + 1);

	while (data->stop == FALSE)
	{
		if (pthread_mutex_lock(&data->fork[right]) != 0)
		{
			ft_putendl("mutex lock failed");
			return (NULL);
		}
		ft_print_state(id, " has taken right fork", data);
		if (pthread_mutex_lock(&data->fork[left]) != 0)
		{
			ft_putendl("mutex lock failed");
			return (NULL);
		}
		ft_print_state(id, " has taken left fork", data);
		ft_eat(id, data);
		if (pthread_mutex_unlock(&data->fork[right]) != 0)
		{
			ft_putendl("mutex unlock failed");
			return (NULL);
		}
		if (pthread_mutex_unlock(&data->fork[left]) != 0)
		{
			ft_putendl("mutex unlock failed");
			return (NULL);
		}
		ft_sleep(id, data);
		ft_print_state(id, " is thinking", data);
	}
	return (NULL);
}

int	ft_create_mutexes(t_data *data)
{
	int	i;

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
	return (SUCCESS);
}
int	ft_create_philo_threads(t_data *data)
{
	int	i;

	data->p_threads = malloc((data->nb - 1) * sizeof(pthread_t));
	if (data->p_threads == NULL)
		return (FAILURE);
	i = 0;
	while (i < data->nb)
	{
		data->selected_philo = i + 1;
		if (pthread_create(&data->p_threads[i], NULL, thread_philo, data))
		{
			ft_putendl("pthread_create failed");
			return (FAILURE);
		}
		usleep(500);
		i++;
	}
	return (SUCCESS);
}

int	ft_join_philo_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb)
	{
		if (pthread_join(data->p_threads[i], NULL))
		{
			ft_putendl("pthread_join failed");
			return (FAILURE);
		}
		// ft_putnbr(i);
		// ft_putendl("");
		// usleep(500);
		// ft_print_state(i + 1, "\033[33mis dead\033[0m", data);
		// printf("The Philosopher [%d] died at %ldms, last meal at: %d\n", data->selected_philo, get_time_in_ms(), *thread_return);
		// return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	 philo_one(t_data *data)
{
	int	i;

	if (ft_create_mutexes(data) == FAILURE)
		return (FAILURE);
	if (ft_create_philo_threads(data) == FAILURE)
		return (FAILURE);
	if (ft_create_death_thread(data) == FAILURE)
		return (FAILURE);
	if (ft_join_philo_threads(data) == FAILURE)
		return (FAILURE);
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
