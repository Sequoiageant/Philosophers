/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 12:24:12 by julnolle          #+#    #+#             */
/*   Updated: 2020/08/18 18:03:20 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"
#include <stdio.h>

void	ft_eat(int id, t_data *data)
{
  printf("Philosophe [%d] mange\n", id);
  usleep(data->eat_t);
}

void	philo_one(char const **av)
{
	size_t		i;
	static char	*args[ARG_NB] = {NB, DIE_T, EAT_T, SLEEP_T, MEAL_NB};

	i = 1;
	while (av[i])
	{
		ft_putstr(args[i - 1]);
		ft_putendl(av[i]);
		i++;
	}
}

int		ft_philo_test(t_data *data)
{
	if (data->nb == 0)
		return (FAILURE);
	return (SUCCESS);
}

int		ft_init(t_data *data, char const **av)
{
	data->nb = ft_atoi(av[1]);
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
			philo_one(av);
		else
			ft_putendl("Wrong number_of_philosophers");
	}
	else
		ft_putendl("Wrong nbr of arguments");
	return (0);
}
