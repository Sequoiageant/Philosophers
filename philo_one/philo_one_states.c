/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_states.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 11:24:40 by julnolle          #+#    #+#             */
/*   Updated: 2020/10/20 11:57:09 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

/*int		check_priority(int id, t_data *data)
{
	int right;
	int left;
	int right_id;

	right_id = id == 0 ? data->nb - 1 : id - 1;
	if (data->meal_nb[id] == 0)
		return (TRUE);
	right = data->meal_nb[right_id];
	left = data->meal_nb[id + 1];
	if (data->meal_nb[id] < left && data->meal_nb[id] < right)
		return (TRUE);
	else
		return (FALSE);
}*/

void	ft_eat(int id, t_data *data, int right, int left)
{
	// while (data->stop == FALSE)
	// {
	// 	if (check_priority(id - 1, data) == TRUE)
	// 		break ;
	// 	usleep(200);
	// }
	if (pthread_mutex_lock(&data->fork[right]) != 0)
		return ;
	ft_print_state(id, " has taken a fork", data);
	if (pthread_mutex_lock(&data->fork[left]) != 0)
		return ;
	ft_print_state(id, " has taken a fork", data);
	data->last_meal_time[id - 1] = get_time_in_ms();
	// ft_print_state(id, " \033[33mis eating\033[0m", data);	
	ft_print_state(id, " is eating", data);	
	ft_improved_sleep(data->eat_t, data->stop);
	if (pthread_mutex_unlock(&data->fork[right]) != 0)
		return ;
	if (pthread_mutex_unlock(&data->fork[left]) != 0)
		return ;
	data->meal_nb[id - 1]++;
}

/*void	ft_think(int id, t_data *data)
{
	ft_print_state(id, " is thinking", data);
	// printf("%6ld ms: Philo [%d] is thinking\n", get_time_in_ms(),id);
}
*/
/*void	ft_sleep(int id, t_data *data)
{
	ft_print_state(id, " is sleeping", data);
	// printf("%6ld ms: Philo [%d] is sleeping %dms\n", get_time_in_ms(), id, data->sleep_t);
	ft_improved_sleep(data->sleep_t, data->stop);
	// usleep(data->sleep_t * 1000);
}
*/