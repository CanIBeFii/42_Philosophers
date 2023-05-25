/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:44:39 by fialexan          #+#    #+#             */
/*   Updated: 2023/05/25 16:51:06 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*dinner(void *args)
{
	t_philo		*philo;

	philo = (t_philo *)args;
	if (philo->id % 2 == 0)
		usleep(150);
	while (check_end_dinner(philo) == 0)
	{
		philo_take_forks(philo);
		philo_eat(philo);
		pthread_mutex_unlock(philo->left_fork);
		usleep(150);
		pthread_mutex_unlock(philo->right_fork);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

void	*one_philo(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	philo->start_time = get_time();
	philo->last_meal = philo->start_time;
	philo_think(philo);
	while (check_end_dinner(philo) == 0)
		;
	return (NULL);
}

void	*distribute_dinner(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	if (philo->info->total_philos == 1)
	{
		one_philo(philo);
		return (NULL);
	}
	else
	{
		dinner(philo);
		return (NULL);
	}
}

int	check_end_dinner(t_philo *philo)
{
	int	finnish_eating;
	int	someone_died;

	pthread_mutex_lock(philo->info->death);
	finnish_eating = philo->info->all_eaten;
	someone_died = philo->info->philo_died;
	pthread_mutex_unlock(philo->info->death);
	return (finnish_eating == 1 || someone_died == 1);
}
