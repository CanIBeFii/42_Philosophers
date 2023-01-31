/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:13:31 by fialexan          #+#    #+#             */
/*   Updated: 2023/01/31 18:24:48 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	parser(int argc, char **argv, t_philosopher *philos, t_fork *forks)
{
	int	iterator;

	if (argc != 5 || argc != 6)
	{
		printf("Error!\nUsage ./philosophers number_of_philosophers ");
		printf("time_to_die time_to_eat time_to_sleep ");
		printf("[number_of_times_each_philosopher_must_eat]\n");
		return (0);
	}
	iterator = 0;
	philos = malloc(sizeof(t_philosopher) * argv[2]);
	if (philos == NULL)
		return (0);
}
