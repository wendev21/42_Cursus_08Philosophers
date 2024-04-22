/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:11:50 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/04/22 16:29:38 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *ptr)
{
	t_philo	philo;

	philo = *(t_philo *)ptr;
	if (!(philo.id % 2))
		ft_usleep(100);
	if (!check_death(philo))
		start_eat(philo);
	if (!check_death(philo))
		start_sleep(philo);
	if (!check_death(philo))
		start_think(philo);
return (NULL);
}

int	create_threads(t_program *program, t_philo *philo)
{
	size_t	num_th;
	size_t	i;

	num_th = program->num_of_philos;
	i = 0;
	while (num_th > i)
	{
		if (pthread_create(&philo[i].thread, NULL, &routine, (void *)&philo[i]))
			return (1);
		i++;
	}
	i = 0;
	while (num_th > i)
	{
		if (pthread_join(philo[i].thread, NULL))
			return (1);
		i++;
	}
	if (set_muthex_fork(program) == 1)
		return (1);
	return (0);
}
