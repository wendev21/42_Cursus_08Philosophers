/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:23:37 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/04/23 14:49:39 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo philo)
{
	int	i;
	
	i = 0;
	while (i < philo.program->num_of_philos)
	{
		/*printf("TIME: %zu\n", get_time());
		printf("LAST: %zu\n", philo.last_eaten);
		printf("Resta: %lu Timee-todie: %zu  ID: %d \n \n", (get_time() - philo.program->philo[i].last_eaten),  (philo.program->philo[i].time_to_die), i);
		*/
		if ((get_time() - philo.program->philo[i].last_eaten) >= (philo.program->philo[i].time_to_die))
		{
			philo.program->dead_flag = 1;
			return (1);

		}
		i++;
	}
	return (0);
}

void	start_eat(t_philo philo)
{
	philo.last_eaten = get_time();
	print_msg(EAT, COLOR_GREEN, philo);
}

void	start_sleep(t_philo philo)
{
	print_msg(SLEEP, COLOR_BLUE, philo);
}

void	start_think(t_philo philo)
{
	print_msg(THINK, COLOR_YELLOW, philo);
}
