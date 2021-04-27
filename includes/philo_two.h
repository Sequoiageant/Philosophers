/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 11:51:48 by julnolle          #+#    #+#             */
/*   Updated: 2021/04/27 18:34:20 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include "philo.h"
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <errno.h>

/*
** --------------------------------- Defines ---------------------------------
*/


/*
** -------------------------------- Structures -------------------------------
*/

typedef struct		s_data
{
	sem_t			*forks;
	sem_t			*display;
	pthread_t		*p_threads;
	time_t			*last_meal_time;
	time_t			start_time;
	time_t			die_t;
	time_t			eat_t;
	int				*meal_nb;
	int				nb;
	int				selected_philo;
	int				sleep_t;
	int				max_meals;
	char			stop;
	char			pad[7];
}					t_data;

/*
** -------------------------------- Prototypes -------------------------------
*/

int		ft_create_philo_threads(t_data *data);
int		ft_init(t_data *data, char const **av, int ac);
void	ft_eat(int id, t_data *data);
int		ft_print_state(int id, int state, t_data *data);
// int		ft_print_death(int id, t_data *data);
int		ft_create_death_thread(t_data *data);
int		ft_create_meal_thread(t_data *data);
// int		check_max_meals(t_data *data);

#endif