/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:10:36 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/04/22 12:27:24 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parseo(int argc, char **argv)
{
	(void)argv;
	if (argc != 5 && argc != 6)
		return (1);
	if (check_value(argc, argv) == 1)
		return (1);
	return (0);
}

int	check_value(int argc, char **argv)
{
	int	*num;

	num = malloc(sizeof(int) * argc - 1);
	while (argc > 1)
	{
		argc--;
		if (ft_isnumber(argv[argc]) == 1)
			return (1);
		num[argc - 1] = ft_atoi_short(argv[argc]);
		if (num[argc - 1] == 0 && (argc) != 5)
			return (1);
		if (num[0] > 200)
			return (1);
	}
	return (0);
}
