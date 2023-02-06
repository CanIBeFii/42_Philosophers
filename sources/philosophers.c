/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:24:48 by fialexan          #+#    #+#             */
/*   Updated: 2023/02/06 14:38:16 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philo			*philosophers;
	pthread_mutex_t	*forks;
	int				philo_number;
	int				iter;

	if (parser(argc, argv, &philosophers, &forks) == FAILURE)
		return (0);
	philo_number = ft_atoi(argv[1]);
	iter = 0;
	while (iter < philo_number)
	{
		//pthread_create(&philosophers[iter].thread, NULL);
		iter++;
	}
	free_philosopher(philosophers, forks, philo_number);
	return (0);
}
