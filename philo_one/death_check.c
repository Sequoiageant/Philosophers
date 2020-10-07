/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 11:20:45 by julnolle          #+#    #+#             */
/*   Updated: 2020/10/07 16:07:59 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	*d_thread(void *arg)
{
	t_data	*data;
	int		i;
	int		elapsed_time;

	data = (t_data *)arg;
	i = 0;
	while (data->stop == FALSE)
	{
		i = 0;
		while (i < data->nb)
		{
			// memset(&elapsed_time, 0, sizeof(int));
			if (data->last_meal_time[i] == UNSET)
				elapsed_time = get_time_in_ms() - data->start_time;
			else
				elapsed_time = get_time_in_ms() - data->last_meal_time[i];
			if (elapsed_time > data->die_t)
			{
				ft_print_state(i + 1, " is dead", data);
				// ft_print_death(i + 1, data);
				data->stop = TRUE;
				return (NULL);
			}
			i++;
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