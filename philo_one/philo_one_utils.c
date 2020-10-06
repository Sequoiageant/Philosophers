/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 11:12:56 by julnolle          #+#    #+#             */
/*   Updated: 2020/10/06 17:50:22 by julnolle         ###   ########.fr       */
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
				data->last_meal_time[i] = UNSET;
				i++;
			}
			return (SUCCESS);
		}
	}
	return (FAILURE);
}

int		ft_init(t_data *data, char const **av, int ac)
{
	data->start_time = get_time_in_ms();
	data->nb = ft_atoi(av[1]);
	data->selected_philo = 0;
	data->die_t = ft_atoi(av[2]);
	data->eat_t = ft_atoi(av[3]);
	data->sleep_t = ft_atoi(av[4]);
	data->sb_died = FALSE;
	data->stop = FALSE;
	if (ac == 6)
		data->meal_nb = ft_atoi(av[5]);
	if (ft_philo_test(data) == SUCCESS)
		return (SUCCESS);
	return (FAILURE);
}

int		ft_print_state(int id, char *action, t_data *data)
{
	char	*p_id;
	char	*output;

	if (data->stop != TRUE)
	{
		if (pthread_mutex_lock(&data->display) != 0)
		{
			ft_putendl("mutex lock failed");
			return (FAILURE);
		}
		output = ft_itoa(get_time_in_ms() - data->start_time);
		p_id = ft_itoa(id);
		ft_strjoin_back(" ", &output);
		ft_strjoin_back(p_id, &output);
		ft_strjoin_back(action, &output);
		ft_putendl(output);
		free (p_id);
		free (output);
		// ft_putnbr(get_time_in_ms() - data->start_time);
		
		// ft_putchar(' ');
		// ft_putnbr(id);
		// ft_putchar(' ');
		if (pthread_mutex_unlock(&data->display) != 0)
		{
			ft_putendl("mutex unlock failed");
			return (FAILURE);
		}
	}
	return (SUCCESS);
}
int		ft_print_death(int id, t_data *data)
{
	if (pthread_mutex_lock(&data->display) != 0)
	{
		ft_putendl("mutex lock failed");
		return (FAILURE);
	}
	ft_putnbr(get_time_in_ms() - data->start_time);
	ft_putchar(' ');
	ft_putnbr(id);
	ft_putendl(" died");
	if (pthread_mutex_unlock(&data->display) != 0)
	{
		ft_putendl("mutex unlock failed");
		return (FAILURE);
	}
	return (SUCCESS);
}
