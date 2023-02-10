/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:35:44 by fialexan          #+#    #+#             */
/*   Updated: 2023/02/10 12:27:54 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	free_philosopher(t_table *table, int num)
{
	int	iter;

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
		}
		if (table->philo != NULL)
		{
			iter = 0;
			while (iter < num)
			{
				free(table->philo + iter);
				iter++;
			}
		}
	}
	return (1);
}
