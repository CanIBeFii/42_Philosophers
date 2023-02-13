/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:35:44 by fialexan          #+#    #+#             */
/*   Updated: 2023/02/13 16:54:27 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	free_philosopher(t_table *table, int num)
{
	int	iter;

	usleep(1000);
	if (table != NULL)
	{
		if (table->forks != NULL)
		{
			iter = 0;
			while (iter < num)
			{
				pthread_mutex_destroy(table->forks + iter);
				iter++;
			}
			free(table->forks);
		}
		if (table->philo != NULL)
		{
			iter = 0;
			while (iter < num)
			{
				pthread_mutex_destroy(table->philo[iter].message);
				iter++;
			}
			free(table->philo);
		}
	}
	return (1);
}
