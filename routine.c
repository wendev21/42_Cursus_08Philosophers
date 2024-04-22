/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:23:37 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/04/22 16:35:13 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo philo)
{
	int	i;
	i = 0;
	while (i < philo.program->num_of_philos)
	{
		i++;
	}
	return (0);
}

void	start_eat(t_philo philo)
{
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
