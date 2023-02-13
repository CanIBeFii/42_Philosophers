/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:35:44 by fialexan          #+#    #+#             */
/*   Updated: 2023/02/13 18:18:32 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	free_philosopher(t_table *table, int num)
{
	usleep(1000);
	if (table != NULL)
	{
		if (table->forks != NULL)
			free_forks(table->forks, num);
		if (table->philo != NULL)
			free_philos(table->philo, num);
	}
	return (1);
}

void	free_forks(pthread_mutex_t *forks, int num)
{
	int	iter;

	iter = 0;
	while (iter < num)
	{
		pthread_mutex_destroy(forks + iter);
		iter++;
	}
	free(forks);
}

void	free_philos(t_philo *philo, int num)
{
	int	iter;

	iter = 0;
	while (iter < num)
	{
		pthread_mutex_destroy(philo[iter].message);
		iter++;
	}
	free(philo);
}
