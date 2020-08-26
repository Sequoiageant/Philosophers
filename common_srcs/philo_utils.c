/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 11:34:58 by julnolle          #+#    #+#             */
/*   Updated: 2020/08/26 17:42:50 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	get_time_in_ms(time_t start)
{
	struct timeval	tv;
	time_t			time_ms;

	gettimeofday(&tv, NULL);
	time_ms = (tv.tv_sec * 1000 + tv.tv_usec / 1000) - start;
	return (time_ms);
}

int		ft_putchar(char c)
{
	return ((int)write(1, &c, 1));
}

void	ft_putnbr(long n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		if (n < 0)
		{
			n = -n;
			ft_putchar('-');
		}
		if (n <= 9)
			ft_putchar(n + 48);
		else
		{
			ft_putnbr(n / 10);
			ft_putnbr(n % 10);
		}
	}
}
