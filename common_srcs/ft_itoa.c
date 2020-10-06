/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 19:01:04 by julnolle          #+#    #+#             */
/*   Updated: 2020/10/06 17:31:23 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static size_t	ft_nbrsize(long n)
{
	size_t size;

	if (n == 0)
		size = 1;
	else
	{
		size = (n < 0) ? 1 : 0;
		n = (n < 0) ? -n : n;
		while (n > 0)
		{
			n = n / 10;
			size++;
		}
	}
	return (size);
}

char			*ft_itoa(long n)
{
	size_t	len;
	char	*str;
	long	nb;

	len = ft_nbrsize(n);
	nb = (n < 0) ? - n : n;
	str = NULL;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str)
	{
		str[len] = '\0';
		len--;
		str[len] = (nb == 0) ? '0' : str[len];
		while (nb > 0)
		{
			str[len] = (nb % 10) + '0';
			nb = nb / 10;
			len--;
		}
		if (n < 0)
			str[0] = '-';
	}
	return (str);
}
