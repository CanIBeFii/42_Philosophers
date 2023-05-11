/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:41:40 by fialexan          #+#    #+#             */
/*   Updated: 2023/05/11 13:04:39 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	print_message(t_philo *philo, int message_code)
{
	long long	time;

	pthread_mutex_lock(philo->info->message);
	if (message_code == SLEEP_CODE)
		printf("[%lld] %d is sleeping\n", time_diff(philo->start_time),
			philo->id);
	else if (message_code == EAT_CODE)
		printf("[%lld] %d is eating\n", time_diff(philo->start_time),
			philo->id);
	else if (message_code == THINK_CODE)
		printf("[%lld] %d is thinking\n", time_diff(philo->start_time),
			philo->id);
	else if (message_code == DEATH_CODE)
		printf("[%lld] %d is thinking\n", time_diff(philo->start_time),
			philo->id);
	else if (message_code == FORK_CODE)
	{
		printf("[%lld] %d has taken a fork\n", time_diff(philo->start_time),
			philo->id);
		printf("[%lld] %d has taken a fork\n", time_diff(philo->start_time),
			philo->id);
	}
	pthread_mutex_unlock(philo->info->message);
}
