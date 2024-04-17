/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:27:59 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/04/16 16:21:08 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_value(int argc, char **argv)
{
	t_program	*program;

	//memory
	program = malloc(sizeof(t_program));
	if (init_program(program, argc, argv) == 1)
		return (1);
	printf("%d", program->num_of_philos);
	return (0);
}

int	init_program(t_program *program, int argc, char **argv)
{
	(void)argc;
	program->dead_flag = 0;
	if (pthread_mutex_init(&program->dead_lock, NULL) == -1)
		return (1);
	if (pthread_mutex_init(&program->dead_lock, NULL) == -1)
		return (1);
	if (pthread_mutex_init(&program->meal_lock, NULL) == -1)
		return (1);
	if (pthread_mutex_init(&program->write_lock, NULL) == -1)
		return (1);
	program->num_of_philos = ft_atoi(argv[1]);
	return (0);
}
