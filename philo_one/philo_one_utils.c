/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 11:12:56 by julnolle          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/10/07 18:13:36 by julnolle         ###   ########.fr       */
=======
/*   Updated: 2020/10/07 16:13:30 by julnolle         ###   ########.fr       */
>>>>>>> ff8e5b53f4fd38c171a039edf4432d6ea928f373
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

	if (pthread_mutex_lock(&data->display) != 0)
	{
		ft_putendl("mutex lock failed");
		return (FAILURE);
	}
	if (data->stop == TRUE)
	{
		pthread_mutex_unlock(&data->display);
		return (SUCCESS);
	}
	output = ft_itoa(get_time_in_ms() - data->start_time);
	p_id = ft_itoa(id);
	ft_strjoin_back(" ", &output);
	ft_strjoin_back(p_id, &output);
	ft_strjoin_back(action, &output);
	ft_putendl(output);
	if (pthread_mutex_unlock(&data->display) != 0)
	{
		ft_putendl("mutex unlock failed");
		return (FAILURE);
	}
	free (p_id);
	free (output);
	return (SUCCESS);
}

void	ft_wait(int delay_ms, int stop)
{
	long int	start_sleep;

	if (stop == TRUE)
		return ;
	start_sleep = get_time_in_ms();
	while (get_time_in_ms() - start_sleep < delay_ms)
	{
		usleep(USLEEP_DELAY);
	}
}
