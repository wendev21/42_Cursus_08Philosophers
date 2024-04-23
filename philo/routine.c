/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:23:37 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/04/23 18:21:00 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo philo)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&philo.program->dead_lock);
	while (i < philo.program->num_of_philos)
	{
		pthread_mutex_lock(&philo.program->meal_lock);
		if ((get_time() - philo.program->philo[i].last_eaten)
			>= (philo.program->philo[i].time_to_die))
		{
			philo.program->dead_flag = 1;
			pthread_mutex_unlock(&philo.program->meal_lock);
			return (pthread_mutex_unlock(&philo.program->dead_lock), 1);
		}
		pthread_mutex_unlock(&philo.program->meal_lock);
		if (philo.num_times_to_eat != -1)
		{
			if (philo.num_times_to_eat == philo.meals_eaten)
				return (pthread_mutex_unlock(&philo.program->dead_lock), 1);
		}
		i++;
	}
	pthread_mutex_unlock(&philo.program->dead_lock);
	return (0);
}

void	start_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->program->meal_lock);
	if (philo->program->num_of_philos == 1)
		ft_usleep(philo->time_to_die);
	che
	philo->meals_eaten += 1;
	pthread_mutex_lock(&philo->program->write_lock);
	//printf("ID: [%d] %d\n", philo->id, philo->meals_eaten);
	pthread_mutex_unlock(&philo->program->write_lock);
	ft_usleep(philo->time_to_eat);
	philo->last_eaten = get_time();
	print_msg(EAT, COLOR_GREEN, *philo);
	pthread_mutex_unlock(&philo->program->meal_lock);
}

void	start_sleep(t_philo philo)
{	
	pthread_mutex_lock(&philo.program->meal_lock);
	ft_usleep(philo.time_to_sleep);
	pthread_mutex_unlock(&philo.program->meal_lock);
	print_msg(SLEEP, COLOR_BLUE, philo);
}

void	start_think(t_philo philo)
{
	print_msg(THINK, COLOR_YELLOW, philo);
}
