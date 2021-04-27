/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 12:24:12 by julnolle          #+#    #+#             */
/*   Updated: 2021/04/27 18:22:09 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int	ft_create_sem(t_data *data)
{
	sem_unlink("/forks");
	sem_unlink("/display");
	data->forks = sem_open("/forks", O_CREAT | O_EXCL, S_IRWXU, data->nb);
	if (data->forks == SEM_FAILED)
	{
		ft_putendl(strerror(errno));
		return (FAILURE);
	}
	data->display = sem_open("/display", O_CREAT | O_EXCL, S_IRWXU, 1);
	if (data->display == SEM_FAILED)
	{
		ft_putendl(strerror(errno));
		return (FAILURE);
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
		i++;
	}
	free(data->p_threads);
	return (SUCCESS);
}

int ft_free_all(t_data *data)
{
	if (sem_close(data->forks) || sem_close(data->display))
	{
		ft_putendl("sem_close failed");
		return (FAILURE);
	}
	if (sem_unlink("/forks") < 0 || sem_unlink("/display") < 0) 
	{
		ft_putendl("sem_unlink failed");
		return (FAILURE);
	}
	free(data->last_meal_time);
	free(data->meal_nb);
	return (SUCCESS);
}

int	 philo_two(t_data *data)
{
	if (ft_create_sem(data) == FAILURE)
		return (FAILURE);
	if (ft_create_philo_threads(data) == FAILURE)
		return (FAILURE);
	if (ft_create_death_thread(data) == FAILURE)
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
				philo_two(&data);
		}
	}
	else
		ft_putendl("Wrong nbr of arguments");
	return (0);
}
