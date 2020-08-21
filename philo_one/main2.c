/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 12:24:12 by julnolle          #+#    #+#             */
/*   Updated: 2020/08/20 16:53:07 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"
#include <stdio.h>

void	ft_eat(int id, t_data *data)
{
	printf("Philosophe [%d] mange pendant %dms\n", id, data->eat_t);
	usleep(data->eat_t);
}

/*void	ft_think(int id, t_data *data)
{
	(void)data;
	printf("Philosophe [%d] pense\n", id);
	// usleep(data->eat_t);
}*/

void	ft_sleep(int id, t_data *data)
{
	printf("Philosophe [%d] dort pendant %dms\n", id, data->sleep_t);
	usleep(data->sleep_t);
}

void *thread_philo(void *arg)
{
	t_data *data = (t_data *)arg;
	int			id;
	int			left;
	int			right;

	printf("Nous sommes dans le thread %d.\n", data->selected_philo - 1);

	id = data->selected_philo;
	left = id;
	right = (left + 1) > data->nb ? 1 : (left + 1);
	pthread_mutex_init(&data->fork[left], NULL);
	pthread_mutex_init(&data->fork[right], NULL);

		printf("Philosophe [%d] pense\n",id);
		pthread_mutex_lock(&data->fork[left]);
		printf("Philosophe [%d] possède fork gauche [%d]\n",id,left);
		pthread_mutex_lock(&data->fork[right]);
		printf("Philosophe [%d] possède fork droite [%d]\n",id,right);
		ft_eat(id, data);
		ft_sleep(id, data);
		pthread_mutex_unlock(&data->fork[left]);
		printf("Philosophe [%d] a libéré fork gauche [%d]\n",id,left);
		pthread_mutex_unlock(&data->fork[right]);
		printf("Philosophe [%d] a libéré fork droite [%d]\n",id,right);
		pthread_mutex_destroy(&data->fork[left]);
		pthread_mutex_destroy(&data->fork[right]);

    /* Pour enlever le warning */
	pthread_exit(NULL);
}

int	 philo_one(t_data *data)
{
	pthread_t	thread[data->nb];
	int			i;
	
	i = 1;
	while (i <= data->nb)
	{
		data->selected_philo = i;
		if (pthread_create(&thread[i], NULL, thread_philo, data))
		{
			perror("pthread_create");
			return (FAILURE);
		}
		if (pthread_join(thread[i], NULL))
		{
			perror("pthread_join");
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
			while (1)
				philo_one(&data);
		}
		else
			ft_putendl("Wrong number_of_philosophers");
	}
	else
		ft_putendl("Wrong nbr of arguments");
	return (0);
}
