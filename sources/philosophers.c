/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:30:33 by fialexan          #+#    #+#             */
/*   Updated: 2023/05/09 15:48:10 by fialexan         ###   ########.fr       */
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
	philos = init_philos(&info);
	if (philos == NULL)
	{
		free_info(&info);
		return (1);
	}
	start_dinner(&info, philos);
	free_info(&info);
	free(philos);
	return (0);
}

void	start_dinner(t_info *info, t_philo *philos)
{
	int	iter;

	iter = 0;
	while (iter < info->total_philos)
	{
		pthread_create(&philos[iter].thread, NULL, &dinner, &philos[iter]);
		iter++;
	}
	iter = 0;
	while (iter < info->total_philos)
	{
		pthread_join(philos[iter].thread, NULL);
		iter++;
	}
}
