/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canibefii <canibefii@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:30:28 by fialexan          #+#    #+#             */
/*   Updated: 2023/05/23 15:05:44 by canibefii        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	philo_eat(t_philo *philo)
{
	if (check_end_dinner(philo) == 1)
		return (0);
	print_message(philo, EATING);
	pthread_mutex_lock(philo->info->eat);
	if (philo->num_of_meals > 0)
		philo->num_of_meals--;
	pthread_mutex_unlock(philo->info->eat);
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
	print_message(philo, SLEEPING);
	sleep_checker(philo, philo->info->time_to_sleep);
	return (1);
}

int	philo_think(t_philo *philo)
{
	if (check_end_dinner(philo) == 1)
		return (0);
	print_message(philo, THINKING);
	return (1);
}

int	philo_take_forks(t_philo *philo)
{
	if (check_end_dinner(philo) == 1)
		return (0);
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->left_fork);
	}
	print_message(philo, FORK_TAKEN);
	return (1);
}

void	sleep_checker(t_philo *philo, int total_sleep_time)
{
	long long	begin_time;
	
	total_sleep_time *= 1000;
	begin_time = get_time();
	while (check_end_dinner(philo) == 0)
	{
		if (time_diff(begin_time) >= total_sleep_time)
			break ;
		usleep(50);
	}
}
