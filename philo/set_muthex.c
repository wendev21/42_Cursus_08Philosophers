/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_muthex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:36:36 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/04/23 18:21:04 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_muthex_fork(t_program *program)
{
	int	i;

	i = 0;
	program->fork = malloc(sizeof(pthread_mutex_t) * program->num_of_philos);
	while (program->num_of_philos >= i)
	{
		if (pthread_mutex_init(&program->fork[i], NULL))
			return (printf("error"), 1);
		i++;
	}
	return (0);
}

int	set_muthex_fork(t_program *program)
{
	int i;

	i = 0;
	while (program->num_of_philos - 1 > i)
	{
		program->philo[i].r_fork = &program->fork[i];
		program->philo[i].l_fork = &program->fork[i + 1];
		i++;
	}
	program->philo[i].r_fork = &program->fork[i];
	program->philo[i].l_fork = &program->fork[0];
	return (0);
}
