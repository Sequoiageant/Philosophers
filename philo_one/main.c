/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 12:24:12 by julnolle          #+#    #+#             */
/*   Updated: 2020/08/25 19:46:40 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"
#include <stdio.h>

time_t	get_time_in_ms(time_t start)
{
	struct timeval	tv;
	time_t			time_ms;

	gettimeofday(&tv, NULL);
	time_ms = (tv.tv_sec * 1000 + tv.tv_usec / 1000) - start;
	return (time_ms);
}

void	ft_eat(int id, t_data *data)
{
	data->last_meal_time[id - 1] = get_time_in_ms(data->start_time);
	printf("%6ld ms: Philo [%d] is eating %ldms\n", get_time_in_ms(data->start_time), id, data->eat_t);
	usleep(data->eat_t * 1000);
}

void	ft_think(int id, t_data *data)
{
	printf("%6ld ms: Philo [%d] is thinking\n", get_time_in_ms(data->start_time),id);
}

void	ft_sleep(int id, t_data *data)
{
	printf("%6ld ms: Philo [%d] is sleeping %dms\n", get_time_in_ms(data->start_time), id, data->sleep_t);
	usleep(data->sleep_t * 1000);
}

void *thread_philo(void *arg)
{
	t_data *data = (t_data *)arg;
	int			id;
	int			right;
	int			left;

	// printf("Nous sommes dans le thread %d.\n", data->selected_philo - 1);

	id = data->selected_philo;
	right = id - 1;
	left = (right + 1) > data->nb - 1 ? 0 : (right + 1);

	while (1 && (get_time_in_ms(data->start_time) - data->last_meal_time[id - 1] < data->die_t))
	{

		if (pthread_mutex_lock(&data->fork[right]) != 0)
			ft_putendl("mutex lock failed");
		printf("%6ld ms: Philo [%d] took left fork [%d]\n", get_time_in_ms(data->start_time), id, right);
		if (pthread_mutex_lock(&data->fork[left]) != 0)
			ft_putendl("mutex lock failed");
		printf("%6ld ms: Philo [%d] took right fork [%d]\n", get_time_in_ms(data->start_time), id, left);
		ft_eat(id, data);
		if (pthread_mutex_unlock(&data->fork[right]) != 0)
			ft_putendl("mutex unlock failed");
		printf("%6ld ms: Philo [%d] released left fork [%d]\n", get_time_in_ms(data->start_time), id, right);
		if (pthread_mutex_unlock(&data->fork[left]) != 0)
			ft_putendl("mutex unlock failed");
		printf("%6ld ms: Philo [%d] released right fork [%d]\n", get_time_in_ms(data->start_time), id, left);
		ft_sleep(id, data);
		printf("last_meal_time of philo %d: %ldms\n", id, data->last_meal_time[id - 1]);
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
		printf("creating thread %d\n", i);
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
		printf("The Philosopher [%d] died at %ldms, last meal at: %d\n", data->selected_philo, get_time_in_ms(data->start_time), *thread_return);
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

int		ft_philo_test(t_data *data)
{
	int	i;

	data->fork = NULL;
	data->last_meal_time = NULL;
	if (data->nb > 0)
	{
		data->fork = malloc(sizeof(pthread_mutex_t) * data->nb);
		data->last_meal_time = malloc(sizeof(time_t) * data->nb);
		if (data->fork && data->last_meal_time)
		{
			i = 0;
			while (i < data->nb)
			{
				data->last_meal_time[i] = data->start_time;
				i++;
			}
			return (SUCCESS);
		}
	}
	return (FAILURE);
}

int		ft_init(t_data *data, char const **av, int ac)
{
	data->start_time = get_time_in_ms(0);
	data->nb = ft_atoi(av[1]);
	data->selected_philo = 0;
	data->die_t = ft_atoi(av[2]);
	data->eat_t = ft_atoi(av[3]);
	data->sleep_t = ft_atoi(av[4]);
	if (ac == 6)
		data->meal_nb = ft_atoi(av[5]);
	if (ft_philo_test(data) == SUCCESS)
		return (SUCCESS);
	return (FAILURE);
}

void	print_args(char const **av)
{
	size_t		i;
	static char	*args[ARG_NB] = {NB, DIE_T, EAT_T, SLEEP_T, MEAL_NB};

	ft_putendl("====== settings ======");
	i = 1;
	while (av[i])
	{
		ft_putstr(args[i - 1]);
		ft_putendl(av[i]);
		i++;
	}
	ft_putendl("==== end settings ====\n");
}

void	print_meal_time(t_data data)
{
	int	i;

	i = 0;
	while(i < data.nb)
	{
		printf("meal_time: %ld\n", data.last_meal_time[i]);
		i++;
	}
}

int		main(int ac, char const **av)
{
	t_data	data;

	if (ac == 5 || ac == 6)
	{
		if (ft_init(&data, av, ac) == SUCCESS)
		{
			print_meal_time(data);
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
