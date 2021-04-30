/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two_states.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 11:24:40 by julnolle          #+#    #+#             */
/*   Updated: 2021/04/30 17:19:13 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static int	check_priority(int id, t_data *data)
{
	int i;

	if (data->meal_nb[id] == 0)
		return (TRUE);
	i = 0;
	while(i < data->nb)
	{
		if (data->last_meal_time[id] > data->last_meal_time[i] && i != id)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void		ft_eat(int id, t_data *data)
{
	while (data->stop == CONTINUE)
	{
		if (check_priority(id - 1, data) == TRUE)
			break ;
	}
	sem_wait(data->forks);
	ft_print_state(id, FORK, data);
	sem_wait(data->forks);
	ft_print_state(id, FORK, data);
	ft_print_state(id, EAT, data);	
	data->meal_nb[id - 1]++;
	data->last_meal_time[id - 1] = get_time_in_ms();
	ft_improved_sleep(data->eat_t, data->stop);
	sem_post(data->forks);
	sem_post(data->forks);
}
