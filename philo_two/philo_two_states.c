/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two_states.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 11:24:40 by julnolle          #+#    #+#             */
/*   Updated: 2021/04/27 11:04:40 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	ft_eat(int id, t_data *data)
{
	sem_wait(data->forks);
	ft_print_state(id, " has taken a fork", data);
	sem_wait(data->forks);
	ft_print_state(id, " has taken a fork", data);
	ft_print_state(id, " is eating", data);	
	data->meal_nb[id - 1]++;
	data->last_meal_time[id - 1] = get_time_in_ms();
	// ft_print_state(id, " \033[33mis eating\033[0m", data);
	ft_improved_sleep(data->eat_t, data->stop);
	sem_post(data->forks);
	sem_post(data->forks);
}
