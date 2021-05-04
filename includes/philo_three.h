/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 11:51:48 by julnolle          #+#    #+#             */
/*   Updated: 2021/05/04 19:02:26 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include "philo.h"
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/wait.h>

/*
** --------------------------------- Defines ---------------------------------
*/

# define RUN	0
# define DEAD	1
# define FULL	2

/*
** -------------------------------- Structures -------------------------------
*/

typedef struct		s_data
{
	sem_t			*forks;
	sem_t			*display;
	sem_t			*all_full;
	pid_t			*pids;
	time_t			last_meal_time;
	time_t			start_time;
	time_t			die_t;
	time_t			eat_t;
	time_t			sleep_t;
	int				meal_nb;
	int				nb;
	int				id;
	int				max_meals;
	int				stop;
	char			pad[4];
}					t_data;

/*
** -------------------------------- Prototypes -------------------------------
*/

int					ft_create_philo_processes(t_data *data);
int					ft_init(t_data *data, char const **av, int ac);
void				ft_eat(t_data *data);
int					ft_print_state(t_data *data, int state);
int					ft_create_death_thread(t_data *data);
void				ft_improved_wait(int delay_ms);

#endif
