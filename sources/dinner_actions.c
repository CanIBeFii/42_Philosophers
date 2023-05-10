/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:30:28 by fialexan          #+#    #+#             */
/*   Updated: 2023/05/10 16:35:23 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	philo_eat(t_philo *philo)
{
	long long	time;

	if (check_end_dinner(philo) == 1)
		return (0);
	pthread_mutex_lock(philo->info->message);
	time = get_time();
	printf("[%lld] %d is eating\n", time - philo->start_time, philo->id);
	pthread_mutex_unlock(philo->info->message);
	usleep(philo->info->time_to_eat * 1000);
	philo->last_meal = get_time();
	return (1);
}

int	philo_sleep(t_philo *philo)
{
	long long	time;

	if (check_end_dinner(philo) == 1)
		return (0);
	pthread_mutex_lock(philo->info->message);
	time = get_time();
	printf("[%lld] %d is sleeping\n", time - philo->start_time, philo->id);
	pthread_mutex_unlock(philo->info->message);
	usleep(philo->info->time_to_sleep * 1000);
	return (1);
}

int	philo_think(t_philo *philo)
{
	long long	time;

	if (check_end_dinner(philo) == 1)
		return (0);
	pthread_mutex_lock(philo->info->message);
	time = get_time();
	printf("[%lld] %d is thinking\n", time - philo->start_time, philo->id);
	pthread_mutex_unlock(philo->info->message);
	return (1);
}

int	philo_take_forks(t_philo *philo)
{
	long long	time;

	if (check_end_dinner(philo) == 1)
		return (0);
	pthread_mutex_lock(philo->info->message);
	time = get_time();
	printf("[%lld] %d has taken a fork\n", time, philo->id);
	pthread_mutex_unlock(philo->info->message);
	return (1);
}
