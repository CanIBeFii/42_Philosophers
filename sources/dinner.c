/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:59:37 by fialexan          #+#    #+#             */
/*   Updated: 2023/02/14 13:18:39 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	think_philo(t_philo *philo)
{
	long long	time;

	if (stop_dinner(philo, THINK_CODE) == 0)
	{
		pthread_mutex_lock(philo->message);
		time = get_time_diff(philo->init_time);
		print_message(THINK_CODE, time, philo->philo_num);
		pthread_mutex_unlock(philo->message);
	}
}

void	sleep_philo(t_philo *philo)
{
	long long	time;

	if (stop_dinner(philo, SLEEP_CODE) == 0)
	{
		pthread_mutex_lock(philo->message);
		time = get_time_diff(philo->init_time);
		print_message(SLEEP_CODE, time, philo->philo_num);
		pthread_mutex_unlock(philo->message);
		usleep(philo->time_to_sleep);
	}
}

void	eat_philo(t_philo *philo)
{
	long long	time;

	if (stop_dinner(philo, EAT_CODE) == 0)
	{
		time = get_time_of_day();
		pthread_mutex_lock(philo->message);
		time = get_time_diff(philo->init_time);
		print_message(EAT_CODE, time, philo->philo_num);
		pthread_mutex_unlock(philo->message);
		usleep(philo->time_to_eat);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		philo->last_time_ate = get_time_of_day();
	}
}

void	take_forks(t_philo *philo)
{
	long long	time;

	if (stop_dinner(philo, EAT_CODE) == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->message);
		time = get_time_diff(philo->init_time);
		print_message(FORK_CODE, time, philo->philo_num);
		print_message(FORK_CODE, time, philo->philo_num);
		pthread_mutex_unlock(philo->message);
	}
}

int	stop_dinner(t_philo *philo, int call_function)
{
	long long	time;
	int			times_ate;
	int			max_time_eat;

	time = get_time_of_day();
	times_ate = philo->number_time_eat;
	max_time_eat = philo->max_times_eat;
	if (philo->is_dead == 1)
		return (1);
	if (times_ate == max_time_eat && call_function == EAT_CODE)
	{
		pthread_mutex_lock(philo->message);
		printf("\n\n\n%d\n\n\n", philo->philo_num);
		pthread_mutex_unlock(philo->message);
		philo->is_dead = 1;
		return (1);
	}
	if (time - philo->last_time_ate > philo->time_to_die)
	{
		printf("\n\n\n%d\n\n\n", philo->philo_num);
		philo->is_dead = 1;
		print_message(DIED_CODE, time - philo->init_time, philo->philo_num);
		return (1);
	}
	return (0);
}
