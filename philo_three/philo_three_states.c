/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three_states.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 11:24:40 by julnolle          #+#    #+#             */
/*   Updated: 2021/05/03 16:45:10 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	ft_improved_wait(int delay_ms)
{
	time_t	start_sleep;

	start_sleep = get_time_in_ms();
	while (get_time_in_ms() - start_sleep < delay_ms)
	{
		usleep(USLEEP_DELAY);
	}
}

void	ft_eat(t_data *data)
{
	sem_wait(data->forks);
	ft_print_state(data, FORK);
	sem_wait(data->forks);
	ft_print_state(data, FORK);
	ft_print_state(data, EAT);	
	data->meal_nb++;
	data->last_meal_time = get_time_in_ms();
	ft_improved_wait(data->eat_t);
	sem_post(data->forks);
	sem_post(data->forks);
}
