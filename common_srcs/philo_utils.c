/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 11:34:58 by julnolle          #+#    #+#             */
/*   Updated: 2021/04/27 13:09:30 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	get_time_in_ms()
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int		ft_putendl_fd(char const *s, int fd)
{
	if (!s)
		return (FAILURE);
	if (write(fd, s, ft_strlen(s)) == FAILURE)
		return (FAILURE);
	return ((int)write(1, "\n", 1));
}

void	ft_improved_sleep(int delay_ms, char stop)
{
	time_t	start_sleep;

	if (stop == STOP)
		return ;
	start_sleep = get_time_in_ms();
	while (get_time_in_ms() - start_sleep < delay_ms)
	{
		usleep(USLEEP_DELAY);
	}
}
