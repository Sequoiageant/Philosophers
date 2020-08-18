/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 12:24:12 by julnolle          #+#    #+#             */
/*   Updated: 2020/08/18 12:28:31 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_three(char const **av)
{
	size_t	i;

	i = 1;
	while (av[i])
	{
		ft_putendl(av[i]);
		i++;
	}
}

int		main(int ac, char const **av)
{
	ft_putendl("MAIN PHILO_THREE");
	if (ac == 5)
		philo_three(av);
	else
		ft_putendl("Wrong nbr of arguments");
	return (0);
}
