/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:35:44 by fialexan          #+#    #+#             */
/*   Updated: 2023/02/06 13:56:11 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	free_philosopher(t_philo *philo, pthread_mutex_t *fork, int num)
{
	int	iter;

	iter = 0;
	while (iter < num)
	{
		free(&philo[iter]);
		free(&fork[iter]);
		iter++;
	}
	return (1);
}
