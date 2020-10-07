/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_states.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 11:24:40 by julnolle          #+#    #+#             */
/*   Updated: 2020/10/07 18:06:21 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	ft_eat(int id, t_data *data)
{
	data->last_meal_time[id - 1] = get_time_in_ms();
	ft_print_state(id, " is eating", data);
	// printf("%6ld ms: Philo [%d] is eating %ldms\n", data->last_meal_time[id - 1], id, data->eat_t);
	
	ft_wait(data->eat_t, data->stop);
	// usleep(data->eat_t * 1000);
}

/*void	ft_think(int id, t_data *data)
{
	ft_print_state(id, " is thinking", data);
	// printf("%6ld ms: Philo [%d] is thinking\n", get_time_in_ms(),id);
}
*/
void	ft_sleep(int id, t_data *data)
{
	ft_print_state(id, " is sleeping", data);
	// printf("%6ld ms: Philo [%d] is sleeping %dms\n", get_time_in_ms(), id, data->sleep_t);
	ft_wait(data->sleep_t, data->stop);
	// usleep(data->sleep_t * 1000);
}
