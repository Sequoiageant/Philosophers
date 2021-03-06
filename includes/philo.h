/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:47:17 by julnolle          #+#    #+#             */
/*   Updated: 2021/05/04 19:00:04 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>

/*
** --------------------------------- Defines ---------------------------------
*/

# define SUCCESS	0
# define FAILURE	-1
# define TRUE		1
# define FALSE		0
# define UNSET		-1
# define STOP		's'
# define CONTINUE	'c'
# define ODD		'o'
# define EVEN		'e'

# define USLEEP_DELAY 500

/*
** ---------------------------- Philosophe state -----------------------------
*/

enum	e_state
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIE
};

/*
** ----------------------------- Common prototypes ----------------------------
*/

int			ft_atoi(const char *str);
size_t		ft_strlen(const char *str);
void		ft_putendl_fd(char const *s, int fd);
int			ft_check_args(char const **av);
time_t		get_time_in_ms(void);
void		ft_improved_sleep(int delay_ms, char stop);

#endif
