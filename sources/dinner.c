/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:59:37 by fialexan          #+#    #+#             */
/*   Updated: 2023/02/08 15:01:48 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	dinner(t_philo *philo, pthread_mutex_t *forks, int philo_num);

int	dinner(void *args)
{
	t_table		table;
	long long	time;

	table = *args;
	time = get_time_of_day();
	print_message(DIED_CODE, time - philo.last_time_ate, philo.philo_num);
	philo.last_time_ate = time;
	time = get_time_of_day();
	print_message(FORK_CODE, time - philo.last_time_ate, philo.philo_num);
	philo.last_time_ate = time;
	time = get_time_of_day();
	print_message(EAT_CODE, time - philo.last_time_ate, philo.philo_num);
	philo.last_time_ate = time;
	time = get_time_of_day();
	print_message(SLEEP_CODE, time - philo.last_time_ate, philo.philo_num);
	philo.last_time_ate = time;
	time = get_time_of_day();
	print_message(THINK_CODE, time - philo.last_time_ate, philo.philo_num);
	philo.last_time_ate = time;
	return (0);
}
