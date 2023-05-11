/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:30:28 by fialexan          #+#    #+#             */
/*   Updated: 2023/05/11 15:56:06 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	philo_eat(t_philo *philo)
{
	if (check_end_dinner(philo) == 1)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (0);
	}
	print_message(philo, EAT_CODE);
	philo->last_meal = get_time();
	philo->num_of_meals--;
	usleep(philo->info->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	*philo->l_fork_state = 0;
	usleep(1000);
	pthread_mutex_unlock(philo->right_fork);
	*philo->r_fork_state = 0;
	return (1);
}

int	philo_sleep(t_philo *philo)
{
	if (check_end_dinner(philo) == 1)
		return (0);
	print_message(philo, SLEEP_CODE);
	usleep(philo->info->time_to_sleep * 1000);
	return (1);
}

int	philo_think(t_philo *philo)
{
	if (check_end_dinner(philo) == 1)
		return (0);
	print_message(philo, THINK_CODE);
	return (1);
}

int	philo_take_forks(t_philo *philo)
{
	while (forks_are_free(philo) == 0)
	{
		if (check_end_dinner(philo) == 1)
			return (0);
	}
	if (check_end_dinner(philo) == 1)
		return (0);
	lock_forks(philo);
	if (check_end_dinner(philo) == 1)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (0);
	}
	print_message(philo, FORK_CODE);
	return (1);
}

void	lock_forks(t_philo *philo)
{
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
	*philo->l_fork_state = 1;
	*philo->r_fork_state = 1;
}
