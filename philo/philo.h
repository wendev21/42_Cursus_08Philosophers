/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:50:24 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/04/16 16:27:39 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdbool.h>
# include <string.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include <pthread.h>

# define COLOR_RED "\033[0;31m"
# define COLOR_GREEN "\033[0;32m"
# define COLOR_BLUE "\033[0;36m"
# define COLOR_RESET "\033[0m"

# define TAKE_FORKS "has taken a fork 🍴"
# define THINK "is thinking 🧠"
# define SLEEP "is sleeping 😴"
# define EAT "is eatingi 🍝"
# define DIED "died 💀"

typedef struct s_program t_program;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				num_times_to_eat;
	int				last_eaten;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	t_program		*program;
}	t_philo;

struct s_program
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	int				num_of_philos;
	t_philo			*philo;
};

int		parseo(int argc, char **argv);
int		check_value(int argc, char **argv);
int		ft_isnumber(char *str);
int		ft_atoi_short(char *str);
int		ft_atoi(char *str);
int		init_value(int argc, char **argv);
int		init_program(t_program *program, int argc, char **argv);
#endif
