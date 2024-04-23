/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:27:59 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/04/23 14:33:30 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_value(char **argv, int argc)
{
	t_program	*program;

	program = malloc(sizeof(t_program));
	if (!program)
		return (1);
	if (init_program(program, argv) == 1)
		return (1);
	if (init_philo(argv, program, argc) == 1)
		return (1);
	return (0);
}

int	init_program(t_program *program, char **argv)
{
	program->dead_flag = 0;
	if (pthread_mutex_init(&program->dead_lock, NULL) == -1)
		return (1);
	if (pthread_mutex_init(&program->meal_lock, NULL) == -1)
		return (1);
	if (pthread_mutex_init(&program->write_lock, NULL) == -1)
		return (1);
	program->num_of_philos = ft_atoi(argv[1]);
	return (0);
}

int	init_philo(char **argv, t_program *program, int argc)
{
	int	i;

	i = 0;
	program->philo = malloc(sizeof(t_philo) * program->num_of_philos);
	create_muthex_fork(program);
	while (program->num_of_philos > i)
	{
		program->philo[i].id = i + 1;
		program->philo[i].eating = 0;
		program->philo[i].meals_eaten = 0;
		program->philo[i].time_to_die = ft_atoi(argv[2]);
		program->philo[i].time_to_eat = ft_atoi(argv[3]);
		program->philo[i].time_to_sleep = ft_atoi(argv[4]);
		program->philo[i].num_times_to_eat = -1;
		if (argc == 6)
			program->philo[i].num_times_to_eat = ft_atoi(argv[5]);
		program->philo[i].last_eaten = get_time();
		program->philo[i].program = program;
		i++;
	}
	set_muthex_fork(program);
	if (create_threads(program, program->philo))
		return (1);
	return (0);
}
