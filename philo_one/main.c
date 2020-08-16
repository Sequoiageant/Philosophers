/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 12:24:12 by julnolle          #+#    #+#             */
/*   Updated: 2020/08/16 14:39:21 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_putendl(char const *s)
{
	if (!s)
		return (FAILURE);
	if (write(1, s, ft_strlen(s)) == FAILURE)
		return (FAILURE);
	return ((int)write(1, "\n", 1));
}

void	philosophers(char const **av)
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
	ft_putendl("MAIN PHILO_ONE");
	if (ac == 5)
		philosophers(av);
	else
		ft_putendl("Wrong nbr of arguments");
	return (0);
}
