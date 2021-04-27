/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 12:47:11 by julnolle          #+#    #+#             */
/*   Updated: 2021/04/27 19:29:38 by julnolle         ###   ########.fr       */
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
			ft_putendl_fd("All arguments must be digit", 2);
			return (FAILURE);
		}
		if (ft_strlen(av[i]) > 9)
		{
			ft_putendl_fd("One argument is too large", 2);
			return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}
