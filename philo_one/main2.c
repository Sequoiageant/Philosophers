/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 12:24:12 by julnolle          #+#    #+#             */
/*   Updated: 2020/08/25 11:21:12 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"
#include <stdio.h>

void	ft_eat(int id, t_data *data)
{
	printf("Philosophe [%d] mange pendant %dms\n", id, data->eat_t);
	usleep(data->eat_t);
}

void	ft_think(int id)
{
	printf("Philosophe [%d] pense\n", id);
}

void	ft_sleep(int id, t_data *data)
{
	printf("Philosophe [%d] dort pendant %dms\n", id, data->sleep_t);
	usleep(data->sleep_t);
}

void *thread_philo(void *arg)
{
	t_data *data = (t_data *)arg;
	int			id;
	int			right;
	int			left;

	printf("Nous sommes dans le thread %d.\n", data->selected_philo - 1);

	id = data->selected_philo;
	right = id - 1;
	left = (right + 1) > data->nb - 1 ? 0 : (right + 1);
	while (1)
	{

		if (pthread_mutex_lock(&data->fork[right]) != 0)
			perror("\n mutex lock failed\n");
		printf("Philosophe [%d] possède fork gauche [%d]\n",id,right);
		if (pthread_mutex_lock(&data->fork[left]) != 0)
			perror("\n mutex lock failed\n");
		printf("Philosophe [%d] possède fork droite [%d]\n",id,left);
		ft_eat(id, data);
		if (pthread_mutex_unlock(&data->fork[right]) != 0)
			perror("\n mutex unlock failed\n");
		printf("Philosophe [%d] a libéré fork gauche [%d]\n",id,right);
		if (pthread_mutex_unlock(&data->fork[left]) != 0)
			perror("\n mutex unlock failed\n");
		printf("Philosophe [%d] a libéré fork droite [%d]\n",id,left);
		ft_sleep(id, data);
		ft_think(id);
		printf("Philosophe [%d] pense\n",id);
	}

    /* Pour enlever le warning */
	pthread_exit(NULL);
}

int	 philo_one(t_data *data)
{
	pthread_t	thread[data->nb];
	int			i;
	
	i = 0;
	while (i < data->nb)
	{
		if (pthread_mutex_init(&data->fork[i], NULL) != 0)
		{
			perror("\n mutex init failed\n");
			return (FAILURE);
		}
		
		i++;
	}
	i = 0;
	while (i < data->nb)
	{
		// pthread_mutex_init(&data->fork[i], NULL);
		data->selected_philo = i + 1;
		if (pthread_create(&thread[i], NULL, thread_philo, data))
		{
			perror("pthread_create");
			return (FAILURE);
		}
		usleep(500);
		i++;
	}
	i = 0;
	while (i < data->nb)
	{
		if (pthread_join(thread[i], NULL))
		{
			perror("pthread_join");
			return (FAILURE);
		}
		i++;
	}
	i = 0;	
	while (i < data->nb)
	{
		if (pthread_mutex_destroy(&data->fork[i]) != 0)
		{
			perror("\n mutex destroy failed\n");
			return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}

int		ft_philo_test(t_data *data)
{
	data->fork = NULL;
	if (data->nb > 0)
	{
		data->fork = malloc(sizeof(pthread_mutex_t) * data->nb);
		if (data->fork)
			return (SUCCESS);
	}
	return (FAILURE);
}

int		ft_init(t_data *data, char const **av)
{
	data->nb = ft_atoi(av[1]);
	data->selected_philo = 0;
	data->die_t = ft_atoi(av[2]);
	data->eat_t = ft_atoi(av[3]);
	data->sleep_t = ft_atoi(av[4]);
	data->meal_nb = ft_atoi(av[5]);
	if (ft_philo_test(data) == SUCCESS)
		return (SUCCESS);
	return (FAILURE);
}

int		main(int ac, char const **av)
{
	t_data		data;

	if (ac == 6)
	{
		if (ft_init(&data, av) == SUCCESS)
		{
			philo_one(&data);
		}
		else
			ft_putendl("Wrong number_of_philosophers");
	}
	else
		ft_putendl("Wrong nbr of arguments");
	return (0);
}
