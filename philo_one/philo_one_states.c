/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_states.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 11:24:40 by julnolle          #+#    #+#             */
/*   Updated: 2021/04/27 19:16:47 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		check_priority(int id, t_data *data)
{
	int right_meal;
	int left_meal;
	int right_id;
	int left_id;

	right_id = id == 0 ? data->nb - 1 : id - 1;
	left_id = (id + 1) % data->nb;
	// printf("pos %d: left: %d / right: %d\n", id, left_id, right_id);

	if (data->meal_nb[id] == 0)
		return (TRUE);
	right_meal = data->meal_nb[right_id];
	left_meal = data->meal_nb[left_id];
	if (data->meal_nb[id] <= left_meal && data->meal_nb[id] <= right_meal)
		return (TRUE);
	else
		return (FALSE);
}

void	ft_eat(int id, t_data *data, int right, int left)
{
	// while (data->stop == CONTINUE)
	// {
	// 	if (check_priority(id - 1, data) == TRUE)
	// 		break ;
	// 	usleep(200);
	// }
	if (pthread_mutex_lock(&data->fork[left]) != 0)
		return ;
	ft_print_state(id, FORK, data);
	if (pthread_mutex_lock(&data->fork[right]) != 0)
		return ;
	ft_print_state(id, FORK, data);
	ft_print_state(id, EAT, data);
	data->meal_nb[id - 1]++;
	data->last_meal_time[id - 1] = get_time_in_ms();
	ft_improved_sleep(data->eat_t, data->stop);
	if (pthread_mutex_unlock(&data->fork[left]) != 0)
		return ;
	if (pthread_mutex_unlock(&data->fork[right]) != 0)
		return ;
}
