/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 16:44:28 by julnolle          #+#    #+#             */
/*   Updated: 2021/04/30 11:19:06 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static void	*thread_philo(void *arg)
{
	t_data	*data;
	int		id;
	int		fork_right;
	int		fork_left;

	data = (t_data *)arg;
	id = data->selected_philo + 1;
	fork_right = data->selected_philo;
	if (pthread_mutex_unlock(&data->select) != 0)
	{
		ft_putendl_fd("mutex unlock failed", 2);
		return (NULL);
	}
	fork_left = id % data->nb;
	while (data->stop == CONTINUE)
	{
		ft_eat(id, data, fork_right, fork_left);
		ft_print_state(id, SLEEP, data);
		ft_improved_sleep(data->sleep_t, data->stop);
		ft_print_state(id, THINK, data);
	}
	return (NULL);
}

static int	ft_create_p_threads(t_data *data, char type)
{
	int	i;

	if (type == ODD)
		i = 0;
	if (type == EVEN)
		i = 1;
	while (i < data->nb)
	{
		if (pthread_mutex_lock(&data->select) != 0)
		{
			ft_putendl_fd("mutex lock failed", 2);
			return (FAILURE);
		}
		data->selected_philo = i;
		if (pthread_create(&data->p_threads[i], NULL, thread_philo, data))
		{
			ft_putendl_fd("pthread_create failed", 2);
			return (FAILURE);
		}
		i = i + 2;
		// usleep(500);
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
	if (ft_create_p_threads(data, ODD) == FAILURE)
		return (FAILURE);
	while (1)
	{
		if (are_odd_philo_full(data) == TRUE)
			break ;
		usleep(10);
	}
	if (ft_create_p_threads(data, EVEN) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
