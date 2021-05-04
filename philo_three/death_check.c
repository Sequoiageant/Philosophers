/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 11:20:45 by julnolle          #+#    #+#             */
/*   Updated: 2021/05/04 18:49:36 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	*d_thread(void *arg)
{
	t_data	*data;
	time_t	elapsed_time;

	data = (t_data *)arg;
	while (data->stop == RUN)
	{
		if (data->last_meal_time == UNSET)
			elapsed_time = get_time_in_ms() - data->start_time;
		else
			elapsed_time = get_time_in_ms() - data->last_meal_time;
		if (elapsed_time > data->die_t)
		{
			ft_print_state(data, DIE);
			exit(DEAD);
		}
		usleep(2000);
	}
	return (NULL);
}

int		ft_create_death_thread(t_data *data)
{
	pthread_t death_thread;

	if (pthread_create(&death_thread, NULL, &d_thread, data))
	{
		ft_putendl_fd("pthread_create failed", 2);
		return (FAILURE);
	}
	if (pthread_detach(death_thread) != 0)
	{
		ft_putendl_fd("pthread_detach failed", 2);
		return (FAILURE);
	}
	return (SUCCESS);
}
