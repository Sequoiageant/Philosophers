/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 11:12:56 by julnolle          #+#    #+#             */
/*   Updated: 2021/04/27 19:34:21 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int			ft_malloc_datas(t_data *data)
{
	int	i;

	data->last_meal_time = NULL;
	data->meal_nb = NULL;
	if (data->nb > 1)
	{
		data->last_meal_time = malloc(sizeof(time_t) * data->nb);
		data->meal_nb = malloc(sizeof(int) * data->nb);
		if (data->last_meal_time && data->meal_nb)
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
	data->forks = NULL;
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

static char	check_max_meals(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb)
	{
		if (data->meal_nb[i] < data->max_meals)
			return (CONTINUE);
		i++;
	}
	return (STOP);
}

int			ft_print_state(int id, int state, t_data *data)
{
	sem_wait(data->display);
	if (data->stop != CONTINUE)
	{
		sem_post(data->display);
		return (SUCCESS);
	}
	printf("%ld %d %s\n",
		get_time_in_ms() - data->start_time, id, get_action(state));
	if (state == DIE)
		data->stop = STOP;
	if (state == EAT && data->max_meals != UNSET)
	{
		if (check_max_meals(data) == STOP)
			data->stop = STOP;
	}
	sem_post(data->display);
	return (SUCCESS);
}
