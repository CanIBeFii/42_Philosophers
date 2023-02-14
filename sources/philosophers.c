/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:24:48 by fialexan          #+#    #+#             */
/*   Updated: 2023/02/14 13:02:42 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_table	table;
	int		philo_number;
	int		iter;

	if (parser(argc, argv, &table) == FAILURE)
		return (0);
	philo_number = ft_atoi(argv[1]);
	iter = 0;
	while (iter < philo_number)
	{
		table.philo[iter].thread_num
			= pthread_create(&table.philo[iter].thread,
				NULL, &dinner, &table.philo[iter]);
		iter++;
	}
	iter = 0;
	while (iter < philo_number)
	{
		pthread_join(table.philo[iter].thread_num, 0);
		iter++;
	}
	free_philosopher(&table, philo_number);
	return (0);
}

long long	get_time_of_day(void)
{
	static struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000LL) + (time.tv_usec / 1000));
}

long long	get_time_diff(long long time)
{
	return (get_time_of_day() - time);
}

void	*dinner(void *args)
{
	t_philo		*philo;

	philo = args;
	philo->last_time_ate = get_time_of_day();
	philo->init_time = philo->last_time_ate;
	if (philo->philo_num % 2 == 0)
		usleep(15000);
	while (philo->is_dead == 0)
	{
		eat_philo(philo);
		sleep_philo(philo);
		think_philo(philo);
	}
	return (NULL);
}
