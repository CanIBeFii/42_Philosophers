/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:30:28 by fialexan          #+#    #+#             */
/*   Updated: 2023/05/25 16:50:54 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	philo_eat(t_philo *philo)
{
	if (check_end_dinner(philo) == 1)
		return (0);
	pthread_mutex_lock(philo->info->message);
	printf("%lld %d %s", time_diff(philo->start_time), philo->id, EATING);
	pthread_mutex_unlock(philo->info->message);
	pthread_mutex_lock(philo->eat);
	if (philo->num_of_meals > 0)
		philo->num_of_meals--;
	pthread_mutex_unlock(philo->eat);
	pthread_mutex_lock(philo->time);
	philo->last_meal = get_time();
	pthread_mutex_unlock(philo->time);
	sleep_checker(philo, philo->info->time_to_eat);
	return (1);
}

int	philo_sleep(t_philo *philo)
{
	if (check_end_dinner(philo) == 1)
		return (0);
	pthread_mutex_lock(philo->info->message);
	printf("%lld %d %s", time_diff(philo->start_time), philo->id, SLEEPING);
	pthread_mutex_unlock(philo->info->message);
	sleep_checker(philo, philo->info->time_to_sleep);
	return (1);
}

int	philo_think(t_philo *philo)
{
	if (check_end_dinner(philo) == 1)
		return (0);
	pthread_mutex_lock(philo->info->message);
	printf("%lld %d %s", time_diff(philo->start_time), philo->id, THINKING);
	pthread_mutex_unlock(philo->info->message);
	return (1);
}

int	philo_take_forks(t_philo *philo)
{
	if (check_end_dinner(philo) == 1)
		return (0);
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->left_fork);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
	}
	if (check_end_dinner(philo) == 1)
		return (0);
	pthread_mutex_lock(philo->info->message);
	printf("%lld %d %s", time_diff(philo->start_time), philo->id, FORK_TAKEN);
	printf("%lld %d %s", time_diff(philo->start_time), philo->id, FORK_TAKEN);
	pthread_mutex_unlock(philo->info->message);
	return (1);
}

void	sleep_checker(t_philo *philo, int total_sleep_time)
{
	long long	begin_time;

	begin_time = get_time();
	while (check_end_dinner(philo) == 0)
	{
		if (time_diff(begin_time) >= total_sleep_time)
			break ;
		usleep(100);
	}
}
