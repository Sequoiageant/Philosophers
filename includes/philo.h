/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:47:17 by julnolle          #+#    #+#             */
/*   Updated: 2020/08/19 10:42:41 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

/*
** --------------------------------- Defines ---------------------------------
*/

# define SUCCESS	0
# define FAILURE	-1
# define TRUE		1
# define FALSE		0

# define ARG_NB		5
# define NB			"number_of_forks & philosophers: "
# define DIE_T		"time_to_die: "
# define EAT_T		"time_to_eat: "
# define SLEEP_T	"time_to_sleep: "
# define MEAL_NB	"number_of_time_each_philosophers_must_eat: "

/*
** ---- Philosophe state -----
*/
# define EAT_MASK	0x000001
# define SLEEP_MASK	0x000002
# define THINK_MASK	0x000004


/*
** -------------------------------- Structures -------------------------------
*/

typedef struct		s_data
{
	pthread_mutex_t	*fork;
	int				nb;
	int				selected_philo;
	int				die_t;
	int				eat_t;
	int				sleep_t;
	int				meal_nb;
}					t_data;

/*typedef struct		s_philo
{
	int		num;
	int		state;
}					t_philo;
*/
/*
** ----------------------------- Common prototypes ----------------------------
*/

int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
int		ft_putstr(char const *s);
int		ft_putendl(char const *s);

#endif
