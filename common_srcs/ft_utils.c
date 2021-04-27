/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 16:32:59 by julnolle          #+#    #+#             */
/*   Updated: 2021/04/27 15:16:29 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	ft_putstr(char const *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
}

void	ft_putendl(char const *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
}

/*void	print_args(char const **av)
{
	size_t		i;
	static char	*args[ARG_NB] = {NB, DIE_T, EAT_T, SLEEP_T, MEAL_NB};

	ft_putendl("====== settings ======");
	i = 1;
	while (av[i])
	{
		ft_putstr(args[i - 1]);
		ft_putendl(av[i]);
		i++;
	}
	ft_putendl("==== end settings ====\n");
}
*/