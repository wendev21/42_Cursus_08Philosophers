/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:11:50 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/04/23 18:20:53 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *ptr)
{
	t_philo	philo;

	philo = *(t_philo *)ptr;
	if (!(philo.id % 2))
		ft_usleep(9);
	while (!check_death(philo))
	{
		if (!check_death(philo))
			start_eat(&philo);
		if (!check_death(philo))
			start_sleep(philo);
		if (!check_death(philo))
			start_think(philo);
	}
	return (NULL);
}

void	*monitoring(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo)ptr;
	while (1)
	{
		//check_any death
		//check_all_eaten
	}

}

int	create_threads(t_program *program, t_philo *philo)
{
	size_t	num_th;
	size_t	i;
	pthread_t	monitor;

	num_th = program->num_of_philos;
	i = 0;
	if (pthread_create(&monitor, NULL, &monitoring, (void *)&philo))
		return (1);
	while (num_th > i)
	{
		philo[i].start_time = get_time();
		if (pthread_create(&philo[i].thread, NULL, &routine, (void *)&philo[i]))
			return (1);
		i++;
	}
	if (pthread_join( .thread, NULL))
		return (1);
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
