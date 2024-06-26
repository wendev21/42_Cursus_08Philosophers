/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:06:13 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/04/23 17:15:37 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	if (parseo(argc, argv) == 1)
		return (printf("%sError ❌%s", COLOR_RED, COLOR_RESET), 0);
	if (init_value(argv, argc) == 1)
		return (printf("%sError ❌%s", COLOR_RED, COLOR_RESET), 0);
	return (0);
}
