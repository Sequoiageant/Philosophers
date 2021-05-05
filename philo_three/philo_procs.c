/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_procs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 16:44:28 by julnolle          #+#    #+#             */
/*   Updated: 2021/05/05 10:58:32 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static void	process_philo(t_data *data)
{
	ft_create_death_thread(data);
	while (data->stop == RUN)
	{
		ft_eat(data);
		ft_print_state(data, SLEEP);
		ft_improved_wait(data->sleep_t);
		ft_print_state(data, THINK);
	}
	exit(data->stop);
}

static void	kill_all(t_data *data)
{
	int i;

	i = 0;
	while (i < data->nb)
	{
		kill(data->pids[i], SIGKILL);
		++i;
	}
}

static void	handle_end(t_data *data)
{
	int i;
	int status;

	i = 0;
	while (i < data->nb)
	{
		waitpid(-1, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status) == DEAD)
			break ;
		i++;
	}
	kill_all(data);
}

int			ft_create_philo_processes(t_data *data)
{
	int i;

	data->pids = malloc((data->nb) * sizeof(pid_t));
	if (data->pids == NULL)
		return (FAILURE);
	i = 0;
	while (i < data->nb)
	{
		data->pids[i] = fork();
		if (data->pids[i] == -1)
		{
			ft_putendl_fd("fork process failed", 2);
			return (FAILURE);
		}
		if (data->pids[i] == 0)
		{
			data->id = i + 1;
			process_philo(data);
		}
		i++;
	}
	handle_end(data);
	return (SUCCESS);
}
