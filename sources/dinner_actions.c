/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:30:28 by fialexan          #+#    #+#             */
/*   Updated: 2023/05/09 16:05:31 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	philo_eat(t_philo *philo)
{
	long long	time;

	time = get_time();
	pthread_mutex_lock(philo->info->message);
	printf("[%lld] %d is eating\n", time - philo->start_time, philo->id);
	pthread_mutex_unlock(philo->info->message);

}

void	philo_sleep(t_philo *philo)
{
	long long	time;

	time = get_time();
	pthread_mutex_lock(philo->info->message);
	printf("[%lld] %d is sleeping\n", time - philo->start_time, philo->id);
	pthread_mutex_unlock(philo->info->message);

}

void	philo_think(t_philo *philo)
{
	long long	time;

	time = get_time();
	pthread_mutex_lock(philo->info->message);
	printf("[%lld] %d is thinking\n", time - philo->start_time, philo->id);
	pthread_mutex_unlock(philo->info->message);
}

void	philo_take_forks(t_philo *philo)
{
	long long	time;

	pthread_mutex_lock(philo->info->message);
	time = get_time();
	printf("[%lld] %d has taken a fork\n", time, philo->id);
	pthread_mutex_unlock(philo->info->message);
}

// int	philo_died()