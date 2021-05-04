/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_states.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 11:24:40 by julnolle          #+#    #+#             */
/*   Updated: 2021/05/04 18:52:49 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	ft_eat(int id, t_data *data, int right, int left)
{
	if (pthread_mutex_lock(&data->fork[left]) != 0)
		return ;
	ft_print_state(id, FORK, data);
	if (pthread_mutex_lock(&data->fork[right]) != 0)
		return ;
	ft_print_state(id, FORK, data);
	data->meal_nb[id - 1]++;
	ft_print_state(id, EAT, data);
	data->last_meal_time[id - 1] = get_time_in_ms();
	ft_improved_sleep(data->eat_t, data->stop);
	if (pthread_mutex_unlock(&data->fork[left]) != 0)
		return ;
	if (pthread_mutex_unlock(&data->fork[right]) != 0)
		return ;
}
