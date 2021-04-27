/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:47:17 by julnolle          #+#    #+#             */
/*   Updated: 2021/04/27 15:35:24 by julnolle         ###   ########.fr       */
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

# define USLEEP_DELAY 500

/*
** ---- Philosophe state -----
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

int			ft_atoi(const char *str);
size_t		ft_strlen(const char *str);
int			ft_putchar(char c);
void		ft_putstr(char const *s);
void		ft_putendl(char const *s);
int			ft_putendl_fd(char const *s, int fd);
int			ft_check_args(char const **av);
// void		ft_strjoin_back(char *back, char **src);
// char		*ft_itoa(long n);
// void	print_args(char const **av);
long int	get_time_in_ms(void);
void		ft_improved_sleep(int delay_ms, char stop);

#endif
