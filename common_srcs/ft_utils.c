/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 16:32:59 by julnolle          #+#    #+#             */
/*   Updated: 2020/08/18 12:10:08 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		ft_atoi(const char *str)
{
	size_t	i;
	int		res;

	i = 0;
	res = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (str[0] == '+' || str[0] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (str[0] == '-' ? -res : res);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_putstr(char const *s)
{
	if (!s)
		return (FAILURE);
	return ((int)write(1, s, ft_strlen(s)));
}

int		ft_putendl(char const *s)
{
	if (!s)
		return (FAILURE);
	if (write(1, s, ft_strlen(s)) == FAILURE)
		return (FAILURE);
	return ((int)write(1, "\n", 1));
}
