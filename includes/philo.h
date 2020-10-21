/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:47:17 by julnolle          #+#    #+#             */
/*   Updated: 2020/10/20 12:49:26 by julnolle         ###   ########.fr       */
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
int		ft_check_args(char const **av);
void	ft_strjoin_back(char *back, char **src);
char	*ft_itoa(long n);
// void	print_args(char const **av);
time_t	get_time_in_ms(void);
void	ft_improved_sleep(int delay_ms, int stop);

#endif
