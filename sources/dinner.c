/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:44:39 by fialexan          #+#    #+#             */
/*   Updated: 2023/05/11 15:55:59 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*dinner(void *args)
{
	t_philo		*philo;

	philo = (t_philo *)args;
	if (philo->id % 2 == 0)
		usleep(150);
	while (philo->info->philo_died == 0)
	{
		if (philo_take_forks(philo) == 0)
			return (NULL);
		if (philo_eat(philo) == 0)
			return (NULL);
		if (philo_sleep(philo) == 0)
			return (NULL);
		if (philo_think(philo) == 0)
			return (NULL);
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
	pthread_mutex_lock(philo->info->death);
	if (philo->info->philo_died == 1 || philo->num_of_meals == 0)
	{
		pthread_mutex_unlock(philo->info->death);
		return (1);
	}
	if (time_diff(philo->last_meal) >= philo->info->time_to_die)
	{
		print_message(philo, DEATH_CODE);
		philo->info->philo_died = 1;
		pthread_mutex_unlock(philo->info->death);
		return (1);
	}
	pthread_mutex_unlock(philo->info->death);
	return (0);
}

int	forks_are_free(t_philo *philo)
{
	return (*philo->l_fork_state == 0 && *philo->r_fork_state == 0);
}
