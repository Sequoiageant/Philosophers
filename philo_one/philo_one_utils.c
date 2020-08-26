/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 11:12:56 by julnolle          #+#    #+#             */
/*   Updated: 2020/08/26 17:49:00 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		ft_philo_test(t_data *data)
{
	int	i;

	data->fork = NULL;
	data->last_meal_time = NULL;
	if (data->nb > 1)
	{
		data->fork = malloc(sizeof(pthread_mutex_t) * data->nb);
		data->last_meal_time = malloc(sizeof(time_t) * data->nb);
		if (data->fork && data->last_meal_time)
		{
			i = 0;
			while (i < data->nb)
			{
				data->last_meal_time[i] = data->start_time;
				i++;
			}
			return (SUCCESS);
		}
	}
	return (FAILURE);
}

int		ft_init(t_data *data, char const **av, int ac)
{
	data->start_time = get_time_in_ms(0);
	data->nb = ft_atoi(av[1]);
	data->selected_philo = 0;
	data->die_t = ft_atoi(av[2]);
	data->eat_t = ft_atoi(av[3]);
	data->sleep_t = ft_atoi(av[4]);
	if (ac == 6)
		data->meal_nb = ft_atoi(av[5]);
	if (ft_philo_test(data) == SUCCESS)
		return (SUCCESS);
	return (FAILURE);
}

void	ft_print_state(long time, int id, const char *action, t_data *data)
{
	if (pthread_mutex_lock(&data->display) != 0)
		ft_putendl("mutex lock failed");
	ft_putnbr(time);
	ft_putchar(' ');
	ft_putnbr(id);
	ft_putchar(' ');
	ft_putendl(action);
	if (pthread_mutex_unlock(&data->display) != 0)
		ft_putendl("mutex unlock failed");
}
