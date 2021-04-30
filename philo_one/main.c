/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 12:24:12 by julnolle          #+#    #+#             */
/*   Updated: 2021/04/30 10:40:48 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int	ft_create_mutexes(t_data *data)
{
	int	i;

	if (pthread_mutex_init(&data->display, NULL) != 0)
	{
		ft_putendl_fd("mutex init failed", 2);
		return (FAILURE);
	}
	if (pthread_mutex_init(&data->select, NULL) != 0)
	{
		ft_putendl_fd("mutex init failed", 2);
		return (FAILURE);
	}
	i = 0;
	while (i < data->nb)
	{
		if (pthread_mutex_init(&data->fork[i], NULL) != 0)
		{
			ft_putendl_fd("mutex init failed", 2);
			return (FAILURE);
		}
		++i;
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
			ft_putendl_fd("pthread_join failed", 2);
			return (FAILURE);
		}
		++i;
	}
	free(data->p_threads);
	return (SUCCESS);
}

int ft_free_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb)
	{
		if (pthread_mutex_destroy(&data->fork[i]) != 0)
		{
			ft_putendl_fd("mutex destroy failed", 2);
			return (FAILURE);
		}
		++i;
	}
	if (pthread_mutex_destroy(&data->display) != 0)
	{
		ft_putendl_fd("mutex destroy failed", 2);
		return (FAILURE);
	}
	if (pthread_mutex_destroy(&data->select) != 0)
	{
		ft_putendl_fd("mutex destroy failed", 2);
		return (FAILURE);
	}
	free(data->fork);
	free(data->last_meal_time);
	free(data->meal_nb);
	return (SUCCESS);
}

int	 philo_one(t_data *data)
{
	if (ft_create_mutexes(data) == FAILURE)
		return (FAILURE);
	if (ft_create_philo_threads(data) == FAILURE)
		return (FAILURE);
	if (ft_create_death_thread(data) == FAILURE)
		return (FAILURE);
	// if (data->max_meals != UNSET)
	// {
	// 	if (ft_create_meal_thread(data) == FAILURE)
	// 		return (FAILURE);
	// }
	if (ft_join_philo_threads(data) == FAILURE)
		return (FAILURE);
	ft_free_all(data);
	return (SUCCESS);
}

int		main(int ac, char const **av)
{
	t_data	data;

	if (ac == 5 || ac == 6)
	{
		if (ft_check_args(av) == SUCCESS)
		{
			if (ft_init(&data, av, ac) == SUCCESS)
				philo_one(&data);
		}
	}
	else
		ft_putendl_fd("Wrong nbr of arguments", 2);
	return (0);
}
