/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:23:28 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/04/22 15:11:34 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(long time_requested)
{
	struct	timeval start_time;
	struct	timeval end_time;
	long	actual_time;

	actual_time = 0;
	time_requested *= 1000;
	gettimeofday(&start_time, NULL);
	while (actual_time < time_requested)
	{
		usleep(1);
		gettimeofday(&end_time, NULL);
		actual_time = (end_time.tv_sec - start_time.tv_sec) * 1000000 + (end_time.tv_usec - start_time.tv_usec);
	}
}
