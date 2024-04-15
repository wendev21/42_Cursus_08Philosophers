/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:27:50 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/04/15 14:39:43 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
/*
 struct timeval
{
     time_t      tv_sec; seconds
     suseconds_t tv_usec; microseconds
 };
*/
size_t	get_time(void) //returns time in milliseconds
{
	struct timeval tv;
	if (gettimeofday(&tv, NULL))
		return (0);
	return (tv.tv_sec * 1000  + (tv.tv_usec / 1000));
}

void	example_1()
{
	struct	timeval time;

	if(gettimeofday(&time, NULL))
		return ;
	printf("%ld seconds\n", time.tv_sec);
	printf("%d microseconds\n", time.tv_usec);
	printf("%ld years passed since 1970 \n", time.tv_sec/60/60/24/365);
}

void	example_2()
{
	size_t	start_time;
	size_t	now;
	
	start_time = get_time();
	usleep(10000);
	now = get_time();
	printf("%zu start_time\n", start_time);
	printf("%zu now\n", now);
	printf("%zu milliseconds passed since the start\n", now - start_time);
}

int main()
{
	example_1();
	example_2();
	return (0);
}
