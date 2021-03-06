/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 11:51:48 by julnolle          #+#    #+#             */
/*   Updated: 2021/05/05 15:56:58 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include "philo.h"
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>

/*
** -------------------------------- Structures -------------------------------
*/

typedef struct		s_data
{
	sem_t			*forks;
	sem_t			*display;
	sem_t			*start;
	pthread_t		*p_threads;
	time_t			*last_meal_time;
	time_t			start_time;
	time_t			die_t;
	time_t			eat_t;
	time_t			sleep_t;
	int				*meal_nb;
	int				nb;
	int				selected_philo;
	int				max_meals;
	char			stop;
	char			pad[3];
}					t_data;

/*
** -------------------------------- Prototypes -------------------------------
*/

int					ft_create_philo_threads(t_data *data);
int					ft_init(t_data *data, char const **av, int ac);
int					ft_print_state(int id, int state, t_data *data);
int					ft_create_death_thread(t_data *data);

#endif
