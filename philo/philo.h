/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:50:24 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/04/23 18:20:57 by wecorzo-         ###   ########.fr       */
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
# include <sys/time.h>
# include <time.h>
# include <sys/types.h>
# include <pthread.h>

# define COLOR_RED "\033[0;31m"
# define COLOR_GREEN "\033[0;32m"
# define COLOR_BLUE "\033[0;36m"
# define COLOR_YELLOW "\x1B[33m"
# define COLOR_RESET "\033[0m"

# define TAKE_FORKS "has taken a fork 🍴"
# define THINK "is thinking 🧠"
# define SLEEP "is sleeping 😴"
# define EAT "is eating 🍝"
# define DIED "died 💀"

typedef struct s_program	t_program;

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
	size_t			start_time;
	size_t			last_eaten;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	t_program		*program;
}	t_philo;

struct s_program
{
	int				dead_flag;
	pthread_mutex_t	*fork;
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
int		init_value(char **argv, int argc);
int		init_program(t_program *program, char **argv);
int		init_philo(char **argv, t_program *program, int argc);
int		create_threads(t_program *program, t_philo *philo);
int		set_muthex_fork(t_program *program);
int		create_muthex_fork(t_program *program);
void	ft_usleep(long time_requested);
int		check_death(t_philo philo);
void	start_eat(t_philo *philo);
void	start_sleep(t_philo philo);
void	start_think(t_philo philo);
void	print_msg(char *str, char *color, t_philo philo);
size_t	get_time(void);
int		loop_death(t_philo *philo);
void	free_all(t_program *program);
#endif
