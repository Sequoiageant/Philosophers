/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 16:44:28 by julnolle          #+#    #+#             */
/*   Updated: 2021/05/05 15:55:45 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static void	ft_eat(int id, t_data *data)
{
	sem_wait(data->forks);
	sem_wait(data->forks);
	ft_print_state(id, FORK, data);
	ft_print_state(id, FORK, data);
	data->meal_nb[id - 1]++;
	ft_print_state(id, EAT, data);
	data->last_meal_time[id - 1] = get_time_in_ms();
	ft_improved_sleep(data->eat_t, data->stop);
	sem_post(data->forks);
	sem_post(data->forks);
}

static void	*thread_philo(void *arg)
{
	t_data	*data;
	int		id;

	data = (t_data *)arg;
	id = data->selected_philo;
	sem_post(data->start);
	while (data->stop == CONTINUE)
	{
		ft_eat(id, data);
		ft_print_state(id, SLEEP, data);
		ft_improved_sleep(data->sleep_t, data->stop);
		ft_print_state(id, THINK, data);
	}
	return (NULL);
}

int			ft_create_philo_threads(t_data *data)
{
	int i;

	data->p_threads = malloc((data->nb) * sizeof(pthread_t));
	if (data->p_threads == NULL)
		return (FAILURE);
	i = 0;
	while (i < data->nb)
	{
		sem_wait(data->start);
		data->selected_philo = i + 1;
		if (pthread_create(&data->p_threads[i], NULL, thread_philo, data))
		{
			ft_putendl_fd("pthread_create failed", 2);
			return (FAILURE);
		}
		++i;
	}
	return (SUCCESS);
}
