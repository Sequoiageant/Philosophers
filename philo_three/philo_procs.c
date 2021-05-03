/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_procs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 16:44:28 by julnolle          #+#    #+#             */
/*   Updated: 2021/05/03 18:31:49 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static void	process_philo(t_data *data)
{
	// printf("PHILO %d CREATED\n", data->id);
	ft_create_death_thread(data);
	while (data->stop == CONTINUE)
	{
		ft_eat(data);
		ft_print_state(data, SLEEP);
		ft_improved_wait(data->sleep_t);
		ft_print_state(data, THINK);
	}
	if (data->stop == STOP)
	{
		printf("%s\n", "DEATH");
		exit(0);
	}
	printf("%s\n", "FULL");
	exit(1);
}

void		kill_all(t_data *data)
{
	int i;

	i = 0;
	while (i < data->nb)
	{
		printf("KILL %d\n", i);
		kill(data->pids[i], SIGKILL);
		++i;
	}
}

int			ft_create_philo_processes(t_data *data)
{
	int i;
	int status;	

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
	printf("%s\n", "AVANT WAIT");
	waitpid(-1, &status, 0);
	if (WIFEXITED(status) == 0)
		kill_all(data);
	usleep(1000000);
	printf("%s\n", "APRES WAIT");

	return (SUCCESS);
	// return (SUCCESS);
}

