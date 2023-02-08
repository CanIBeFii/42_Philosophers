/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:24:48 by fialexan          #+#    #+#             */
/*   Updated: 2023/02/08 13:58:22 by fialexan         ###   ########.fr       */
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
		philo[iter].thread_num = pthread_create(&philo[iter].thread,
				NULL, &dinner, );
		iter++;
	}
	iter = 0;
	while (iter < philo_number)
	{
		pthread_join(philo[iter].thread_num, 0);
		iter++;
	}
	free_philosopher(philo, forks, philo_number);
	return (0);
}

long long	get_time_of_day(void)
{
	static struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000LL) + (time.tv_usec / 1000));
}
