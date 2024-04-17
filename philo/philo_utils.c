/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:43:58 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/04/16 16:21:56 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}

int	ft_atoi_short(char *str)
{
	int	i;
	int	num;

	i = 0;
	num  = 0;
	while(str[i])
	{
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	return (num);
}

int ft_atoi(char *str)
{
	int	num;
	int sign;
	int	i;

	num = 0;
	sign = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '	'))
		i++;
	if (str[i] == '-' )
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num *= 10;
		num += (str[i] - '0');
		i++;
	}
	return (num * sign);
}
