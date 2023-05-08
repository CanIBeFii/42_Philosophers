/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:44:39 by fialexan          #+#    #+#             */
/*   Updated: 2023/05/08 12:59:02 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	dinner(t_philo *philo)
{
	long long	time;

	time = get_time();
	while (1)
	{
		if (philo->info->total_philos == 1)
		{
			print_message(philo, "has taken a fork");
			print_message(philo, "is eating");
			usleep(philo->info->time_to_eat * 1000);
			print_message(philo, "is sleeping");
			usleep(philo->info->time_to_sleep * 1000);
			print_message(philo, "is thinking");
		}
		else
		{
			if (philo->id % 2 == 0)
				even_philo(philo, time);
			else
				odd_philo(philo, time);
		}
	}
}
