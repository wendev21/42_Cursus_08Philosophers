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


void	start_eat(t_philo *philo)
{
	pthread_mutex_lock((*philo).r_fork);
	print_msg(TAKE_FORKS, COLOR_YELLOW, *philo);
	if (philo->program->num_of_philos == 1)
	{
		(ft_usleep(philo->time_to_die), pthread_mutex_unlock((*philo).r_fork));
		return ;
	}
	pthread_mutex_lock((*philo).l_fork);
	print_msg(TAKE_FORKS, COLOR_YELLOW, *philo);
	print_msg(EAT, COLOR_GREEN, *philo);
	pthread_mutex_lock(&philo->program->meal_lock);
	philo->meals_eaten += 1;
	philo->last_eaten = get_time();
	pthread_mutex_unlock(&philo->program->meal_lock);
	ft_usleep(philo->time_to_eat);
	pthread_mutex_unlock((*philo).r_fork);
	pthread_mutex_unlock((*philo).l_fork);
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
