/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:47:17 by julnolle          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/10/07 18:02:24 by julnolle         ###   ########.fr       */
=======
/*   Updated: 2020/10/07 16:00:13 by julnolle         ###   ########.fr       */
>>>>>>> ff8e5b53f4fd38c171a039edf4432d6ea928f373
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

# define ARG_NB		5
# define NB			"number_of_forks & philosophers: "
# define DIE_T		"time_to_die (ms): "
# define EAT_T		"time_to_eat (ms): "
# define SLEEP_T	"time_to_sleep (ms): "
# define MEAL_NB	"number_of_time_each_philosophers_must_eat: "

# define USLEEP_DELAY 500

/*
** ---- Philosophe state -----
# define EAT_MASK	0x000001
# define SLEEP_MASK	0x000002
# define THINK_MASK	0x000004
*/


/*
** -------------------------------- Structures -------------------------------
*/

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
int		ft_putchar(char c);
void	ft_putstr(char const *s);
void	ft_putendl(char const *s);
int		ft_putendl_fd(char const *s, int fd);
void	ft_putnbr(long n);
void	ft_strjoin_back(char *back, char **src);
char	*ft_itoa(long n);
void	print_args(char const **av);
time_t	get_time_in_ms();

#endif
