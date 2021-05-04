/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 12:24:12 by julnolle          #+#    #+#             */
/*   Updated: 2021/05/04 18:46:46 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int	ft_create_sem(t_data *data)
{
	sem_unlink("/forks");
	sem_unlink("/display");
	sem_unlink("/all_full");
	data->forks = sem_open("/forks", O_CREAT | O_EXCL, S_IRWXU, data->nb);
	if (data->forks == SEM_FAILED)
	{
		ft_putendl_fd("sem_open failed", 2);
		return (FAILURE);
	}
	data->display = sem_open("/display", O_CREAT | O_EXCL, S_IRWXU, 1);
	if (data->display == SEM_FAILED)
	{
		ft_putendl_fd("sem_open failed", 2);
		return (FAILURE);
	}
	data->all_full = sem_open("/all_full", O_CREAT | O_EXCL, S_IRWXU, data->nb - 1);
	if (data->all_full == SEM_FAILED)
	{
		ft_putendl_fd("sem_open failed", 2);
		return (FAILURE);
	}
	return (SUCCESS);
}

int	ft_free_all(t_data *data)
{
	if (sem_close(data->forks) || sem_close(data->display))
	{
		ft_putendl_fd("sem_close failed", 2);
		return (FAILURE);
	}
	if (sem_unlink("/forks") < 0)
	{
		ft_putendl_fd("sem_unlink fork failed", 2);
		return (FAILURE);
	}
	if (sem_unlink("/display") < 0)
	{
		ft_putendl_fd("sem_unlink display failed", 2);
		return (FAILURE);
	}
	if (sem_unlink("/all_full") < 0)
	{
		ft_putendl_fd("sem_unlink all_full failed", 0);
		return (FAILURE);
	}
	free(data->pids);
	return (SUCCESS);
}

int	philo_three(t_data *data)
{
	if (ft_create_sem(data) == FAILURE)
		return (FAILURE);
	if (ft_create_philo_processes(data) == FAILURE)
		return (FAILURE);
	ft_free_all(data);
	return (SUCCESS);
}

int	main(int ac, char const **av)
{
	t_data	data;

	if (ac == 5 || ac == 6)
	{
		if (ft_check_args(av) == SUCCESS)
		{
			if (ft_init(&data, av, ac) == SUCCESS)
				philo_three(&data);
		}
	}
	else
		ft_putendl_fd("Wrong nbr of arguments", 2);
	return (0);
}
