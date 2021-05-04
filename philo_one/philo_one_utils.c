/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 11:12:56 by julnolle          #+#    #+#             */
/*   Updated: 2021/05/04 18:52:25 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static int	ft_malloc_datas(t_data *data)
{
	int	i;

	data->fork = NULL;
	data->last_meal_time = NULL;
	data->meal_nb = NULL;
	if (data->nb > 1)
	{
		data->fork = malloc(sizeof(pthread_mutex_t) * data->nb);
		data->last_meal_time = malloc(sizeof(time_t) * data->nb);
		data->meal_nb = malloc(sizeof(int) * data->nb);
		if (data->fork && data->last_meal_time && data->meal_nb)
		{
			i = 0;
			while (i < data->nb)
			{
				data->last_meal_time[i] = UNSET;
				data->meal_nb[i] = 0;
				i++;
			}
			return (SUCCESS);
		}
	}
	return (FAILURE);
}

int			ft_init(t_data *data, char const **av, int ac)
{
	data->start_time = get_time_in_ms();
	data->nb = ft_atoi(av[1]);
	if (data->nb < 2)
	{
		ft_putendl_fd("The simulation needs at least 2 philosophers to run", 2);
		return (FAILURE);
	}
	data->selected_philo = 0;
	data->die_t = ft_atoi(av[2]);
	data->eat_t = ft_atoi(av[3]);
	data->sleep_t = ft_atoi(av[4]);
	data->stop = CONTINUE;
	if (ac == 6)
		data->max_meals = ft_atoi(av[5]);
	else
		data->max_meals = UNSET;
	if (ft_malloc_datas(data) == SUCCESS)
		return (SUCCESS);
	return (FAILURE);
}

static char	*get_action(int state)
{
	if (state == FORK)
		return ("has taken a fork");
	else if (state == EAT)
		return ("is eating");
	else if (state == SLEEP)
		return ("is sleeping");
	else if (state == THINK)
		return ("is thinking");
	else if (state == DIE)
		return ("died");
	else
		return ("died");
}

int			ft_print_state(int id, int state, t_data *data)
{
	if (pthread_mutex_lock(&data->display) != 0)
	{
		ft_putendl_fd("mutex lock failed", 2);
		return (FAILURE);
	}
	if (data->stop == STOP)
	{
		pthread_mutex_unlock(&data->display);
		return (SUCCESS);
	}
	printf("%ld %d %s\n",
		get_time_in_ms() - data->start_time, id, get_action(state));
	check_stop(data, state);
	if (pthread_mutex_unlock(&data->display) != 0)
	{
		ft_putendl_fd("mutex unlock failed", 2);
		return (FAILURE);
	}
	return (SUCCESS);
}
