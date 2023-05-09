/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:44:39 by fialexan          #+#    #+#             */
/*   Updated: 2023/05/09 16:03:08 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*dinner(void *args)
{
	t_philo		*philo;
	long long	time;
	// int			iter;

	philo = (t_philo *)args;
	time = get_time();
	philo->last_meal = time;
	philo->start_time = time;
	philo_eat(philo);
	philo_sleep(philo);
	philo_think(philo);
	return (NULL);
}
