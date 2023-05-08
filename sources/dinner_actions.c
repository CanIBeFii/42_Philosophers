/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:30:28 by fialexan          #+#    #+#             */
/*   Updated: 2023/05/08 12:48:26 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->message);
	printf("[%lld] %d is eating\n", get_time(), philo->id);
	pthread_mutex_unlock(&philo->info->message);

}

void	philo_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->message);
	printf("[%lld] %d is sleeping\n", get_time(), philo->id);
	pthread_mutex_unlock(&philo->info->message);

}

void	philo_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->message);
	printf("[%lld] %d is thinking\n", get_time(), philo->id);
	pthread_mutex_unlock(&philo->info->message);
}

void	philo_take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->message);
	printf("[%lld] %d has taken a fork\n", get_time(), philo->id);
	pthread_mutex_unlock(&philo->info->message);
}
