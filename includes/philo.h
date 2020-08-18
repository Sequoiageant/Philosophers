/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:47:17 by julnolle          #+#    #+#             */
/*   Updated: 2020/08/17 18:57:55 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>

/*
** --------------------------------- Defines ---------------------------------
*/

# define SUCCESS	0
# define FAILURE	-1
# define TRUE		1
# define FALSE		0

# define ARG_NB		5
# define NB			"number_of_philosophers: "
# define DIE_T		"time_to_die: "
# define EAT_T		"time_to_eat: "
# define SLEEP_T	"time_to_sleep: "
# define MEAL_NB	"number_of_time_each_philosophers_must_eat: "

/*
** -------------------------------- Structures -------------------------------
*/

typedef struct		s_philosophers
{
	int		nb;
	int		die_t;
	int		eat_t;
	int		sleep_t;
	int		meal_nb;
}					t_philo;

/*
** ----------------------------- Common prototypes ----------------------------
*/

int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
int		ft_putstr(char const *s);
int		ft_putendl(char const *s);

#endif
