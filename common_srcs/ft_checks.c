/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 12:47:11 by julnolle          #+#    #+#             */
/*   Updated: 2020/10/20 12:48:38 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	arg_isdigit(char const *av)
{
	int i;

	i = 0;
	while (av[i])
	{
		if (!ft_isdigit(av[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int			ft_check_args(char const **av)
{
	int i;

	i = 1;
	while (av[i])
	{
		if (!arg_isdigit(av[i]))
		{
			ft_putendl("All arguments must be digit");
			return (FAILURE);
		}
		if (ft_strlen(av[i]) > 9)
		{
			ft_putendl("One argument is too large");
			return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}
