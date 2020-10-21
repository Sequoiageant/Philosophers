/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two_states.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 11:24:40 by julnolle          #+#    #+#             */
/*   Updated: 2020/10/21 11:26:49 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	ft_eat(int id, t_data *data)
{
	sem_wait(data->forks);
	ft_print_state(id, " has taken a fork", data);
	sem_wait(data->forks);
	ft_print_state(id, " has taken a fork", data);
	data->last_meal_time[id - 1] = get_time_in_ms();
	ft_print_state(id, " \033[33mis eating\033[0m", data);
	// ft_print_state(id, " is eating", data);	
	ft_improved_sleep(data->eat_t, data->stop);
	sem_post(data->forks);
	sem_post(data->forks);
	data->meal_nb[id - 1]++;
}
