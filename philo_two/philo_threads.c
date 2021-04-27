/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 16:44:28 by julnolle          #+#    #+#             */
/*   Updated: 2021/04/27 17:12:01 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static void	*thread_philo(void *arg)
{
	t_data	*data;
	int		id;

	data = (t_data *)arg;
	id = data->selected_philo;
	while (data->stop == CONTINUE)
	{
		ft_eat(id, data);
		ft_print_state(id, "is sleeping", data);
		ft_improved_sleep(data->sleep_t, data->stop);
		ft_print_state(id, "is thinking", data);
	}
	return (NULL);
}

static int	ft_create_odd_philo_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb)
	{
		data->selected_philo = i + 1;
		if (pthread_create(&data->p_threads[i], NULL, thread_philo, data))
		{
			ft_putendl("pthread_create failed");
			return (FAILURE);
		}
		i = i + 2;
		usleep(500);
	}
	return (SUCCESS);
}

static int	ft_create_even_philo_threads(t_data *data)
{
	int	i;

	i = 1;
	while (i < data->nb)
	{
		data->selected_philo = i + 1;
		if (pthread_create(&data->p_threads[i], NULL, thread_philo, data))
		{
			ft_putendl("pthread_create failed");
			return (FAILURE);
		}
		i = i + 2;
		usleep(500);
	}
	return (SUCCESS);
}

static int	are_odd_philo_full(t_data *data)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (i < data->nb)
	{
		if (data->last_meal_time[i] != UNSET)
			count++;
		i = i + 2;
	}
	if (count == data->nb / 2)
		return (TRUE);
	else
		return (FALSE);
}

int			ft_create_philo_threads(t_data *data)
{
	data->p_threads = malloc((data->nb) * sizeof(pthread_t));
	if (data->p_threads == NULL)
		return (FAILURE);
	if (ft_create_odd_philo_threads(data) == FAILURE)
		return (FAILURE);
	while (1)
	{
		if (are_odd_philo_full(data) == TRUE)
			break ;
		usleep(10);
	}
	if (ft_create_even_philo_threads(data) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

