/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:30:33 by fialexan          #+#    #+#             */
/*   Updated: 2023/05/10 16:34:31 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_info	info;
	t_philo	*philos;

	if (parse_input(&info, argc, argv) == 0)
	{
		return (1);
	}
	philos = init_philos(info);
	if (philos == NULL)
	{
		free_info(&info);
		return (1);
	}
	start_dinner(info, philos);
	free_info(&info);
	free(philos);
	return (0);
}

void	start_dinner(t_info info, t_philo *philos)
{
	int			iter;
	long long	time;

	iter = -1;
	if (info.total_philos == 1)
	{
		philos[0].info = &info;
		pthread_create(&philos[0].thread, NULL, &one_philo, &philos[0]);
	}
	else
	{
		time = get_time();
		while (++iter < info.total_philos)
		{
			philos[iter].start_time = time;
			philos[iter].last_meal = time;
			philos[iter].info = &info;
			pthread_create(&philos[iter].thread, NULL, &dinner, &philos[iter]);
		}
	}
	iter = -1;
	while (++iter < info.total_philos)
		pthread_join(philos[iter].thread, NULL);
}
