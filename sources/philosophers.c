/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:30:33 by fialexan          #+#    #+#             */
/*   Updated: 2023/05/11 15:05:29 by fialexan         ###   ########.fr       */
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
	time = get_time();
	while (++iter < info.total_philos)
	{
		philos[iter].start_time = time;
		philos[iter].last_meal = time;
		philos[iter].info = &info;
		philos[iter].l_fork_state = &info.is_fork_used[iter];
		philos[iter].r_fork_state
			= &info.is_fork_used[iter % philos[iter].info->total_philos];
		pthread_create(&philos[iter].thread, NULL, &distribute_dinner,
			&philos[iter]);
	}
	iter = -1;
	while (++iter < info.total_philos)
		pthread_join(philos[iter].thread, NULL);
}
