/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 11:51:48 by julnolle          #+#    #+#             */
/*   Updated: 2021/04/27 11:20:27 by julnolle         ###   ########.fr       */
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
	pthread_mutex_t	display;
	pthread_mutex_t	*fork;
	pthread_t		*p_threads;
	time_t			*last_meal_time;
	time_t			start_time;
	int				*meal_nb;
	int				nb;
	int				selected_philo;
	int				die_t;
	int				eat_t;
	int				sleep_t;
	int				max_meals;
	char			stop;
	char			pad[7];
}					t_data;

/*
** -------------------------------- Prototypes -------------------------------
*/

// int		ft_philo_test(t_data *data);
int		ft_create_philo_threads(t_data *data);
int		ft_init(t_data *data, char const **av, int ac);
void	ft_eat(int id, t_data *data, int right, int left);
// void	ft_think(int id, t_data *data);
// void	ft_sleep(int id, t_data *data);
int		ft_print_state(int id, char *action, t_data *data);
int		ft_print_death(int id, t_data *data);
int		ft_create_death_thread(t_data *data);
char	check_max_meals(t_data *data);

#endif