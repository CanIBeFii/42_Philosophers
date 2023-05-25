/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_brother.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:46:28 by canibefii         #+#    #+#             */
/*   Updated: 2023/05/25 16:26:39 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*big_brother_eat(void *args)
{
	t_philo	*philos;

	philos = (t_philo *)args;
	while (check_end_dinner(philos) == 0)
	{
		if (philos_finnish_eating(philos) == 1)
			return (NULL);
	}
	return (NULL);
}

int	philos_finnish_eating(t_philo *philos)
{
	int	iter;
	int	total_philos;

	iter = 0;
	total_philos = philos->info->total_philos;
	while (iter < total_philos)
	{
		pthread_mutex_lock(philos[iter].eat);
		if (philos[iter].num_of_meals > 0)
		{
			pthread_mutex_unlock(philos[iter].eat);
			return (0);
		}
		pthread_mutex_unlock(philos[iter].eat);
		iter++;
	}
	pthread_mutex_lock(philos->info->death);
	philos->info->all_eaten = 1;
	pthread_mutex_unlock(philos->info->death);
	return (1);
}

void	*big_brother_death(void *args)
{
	t_philo	*philos;
	int		iter;

	philos = (t_philo *)args;
	while (check_end_dinner(philos) == 0)
	{
		iter = 0;
		while (iter < philos->info->total_philos)
		{
			pthread_mutex_lock(philos[iter].time);
			if (time_diff(philos[iter].last_meal) >= philos->info->time_to_die)
			{
				pthread_mutex_unlock(philos[iter].time);
				kill_philo(&philos[iter]);
				return (NULL);
			}
			pthread_mutex_unlock(philos[iter].time);
			iter++;
		}
	}
	return (NULL);
}

void	kill_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->info->death);
	pthread_mutex_lock(philo->info->message);
	printf("%lld %d %s", time_diff(philo->start_time), philo->id, DIED);
	pthread_mutex_unlock(philo->info->message);
	philo->info->philo_died = 1;
	pthread_mutex_unlock(philo->info->death);
}
