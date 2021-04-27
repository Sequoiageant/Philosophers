/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 11:20:45 by julnolle          #+#    #+#             */
/*   Updated: 2021/04/27 18:43:09 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

/*static char	check_max_meals(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb)
	{
		if (data->meal_nb[i] < data->max_meals)
			return (CONTINUE);
		++i;
		// usleep(10);
	}
	data->stop = STOP;
	return (STOP);
}

static void	*m_thread(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (data->stop == CONTINUE)
	{
		check_max_meals(data);
		usleep(10);
	}
	return (NULL);
}*/

/*char	check_max_meals(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb)
	{
		if (data->meal_nb[i] < data->max_meals)
			return (CONTINUE);
		i++;
		usleep(10);
	}
	return (STOP);
}*/

void	*d_thread(void *arg)
{
	t_data	*data;
	int		i;
	int		count;
	int		elapsed_time;

	data = (t_data *)arg;
	i = 0;
	while (data->stop == CONTINUE)
	{
		i = 0;
		count = 0;
		while (i < data->nb)
		{
			if (data->last_meal_time[i] == UNSET)
				elapsed_time = get_time_in_ms() - data->start_time;
			else
				elapsed_time = get_time_in_ms() - data->last_meal_time[i];
			if (elapsed_time > data->die_t)
			{
				ft_print_state(i + 1, DIE, data);
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