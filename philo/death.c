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

int loop_death(t_philo *philo)
{
    int i;
    i = 0;
    while(philo->program->num_of_philos - 1 > i)
    {
        pthread_mutex_lock(&philo->program->meal_lock);
        if ((get_time() - philo->program->philo[i].last_eaten)
        >= (philo->program->philo[i].time_to_die))
		{
            philo[i].program->dead_flag = 1;
            pthread_mutex_unlock(&philo->program->meal_lock);
            return (1);
        }
        pthread_mutex_unlock(&philo->program->meal_lock);
        i++;
    }
    return (0);
}

int	check_death(t_philo philo)
{
	pthread_mutex_lock(&philo.program->dead_lock);
	if (philo.program->dead_flag == 1)
		return (pthread_mutex_unlock(&philo.program->dead_lock), 1);
	pthread_mutex_unlock(&philo.program->dead_lock);
	return (0);
}

void free_all(t_program *program)
{
	int	i;

	i = 0;
	while (program->num_of_philos >  i)
	{
		pthread_mutex_destroy(&program->fork[i]);
		//free(&program->philo[i]);
	}
	pthread_mutex_destroy(&program->dead_lock);
	pthread_mutex_destroy(&program->meal_lock);
	pthread_mutex_destroy(&program->write_lock);
	pthread_mutex_destroy(&program->dead_lock);
	//free(program);
}

