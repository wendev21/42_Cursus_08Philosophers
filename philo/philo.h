/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:50:24 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/04/15 12:32:04 by wecorzo-         ###   ########.fr       */
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

#define  
typedef struct s_phlo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				num_of_philos;
	int				numm_times_to_eatt;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}	t_philo;

typedef struct s_program
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philo;
}	t_program;

struct timeval
{
	time_t		tv_sec;
	suseconds_t	tv_usec;
};

int		parseo(int argc, char **argv);
int		check_value(int argc, char **argv);
int		ft_isnumber(char *str);
int		ft_atoi_short(char *str);
#endif
