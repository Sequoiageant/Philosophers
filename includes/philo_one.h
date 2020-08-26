/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 11:51:48 by julnolle          #+#    #+#             */
/*   Updated: 2020/08/26 17:49:05 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

#include "philo.h"

/*
** --------------------------------- Defines ---------------------------------
*/


/*
** -------------------------------- Structures -------------------------------
*/

typedef struct		s_data
{
	pthread_mutex_t	*fork;
	pthread_mutex_t	display;
	time_t			start_time;
	time_t			*last_meal_time;
	int				nb;
	int				selected_philo;
	time_t			die_t;
	time_t			eat_t;
	int				sleep_t;
	int				meal_nb;
}					t_data;

/*typedef struct		s_mutex
{
	int				var;
	pthread_mutex_t mutex;
}					t_mutex;
*/

/*
** -------------------------------- Prototypes -------------------------------
*/

int		ft_philo_test(t_data *data);
int		ft_init(t_data *data, char const **av, int ac);
void	ft_eat(int id, t_data *data);
void	ft_think(int id, t_data *data);
void	ft_sleep(int id, t_data *data);
void	ft_print_state(long time, int id, const char *action, t_data *data);

#endif