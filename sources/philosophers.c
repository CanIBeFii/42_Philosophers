/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:30:33 by fialexan          #+#    #+#             */
/*   Updated: 2023/05/25 16:31:47 by fialexan         ###   ########.fr       */
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
	while (++iter < info.total_philos)
	{
		time = get_time();
		philos[iter].start_time = time;
		philos[iter].last_meal = time;
		philos[iter].eat = info.eat;
		philos[iter].time = info.time;
		philos[iter].info = &info;
		pthread_create(&philos[iter].thread, NULL, &distribute_dinner,
			&philos[iter]);
	}
	start_big_brother(philos);
	iter = -1;
	while (++iter < info.total_philos)
		pthread_join(philos[iter].thread, NULL);
}

void	start_big_brother(t_philo *philos)
{
	t_thread	death_big_brother;
	t_thread	eat_big_brother;

	pthread_create(&death_big_brother, NULL, &big_brother_death, philos);
	pthread_detach(death_big_brother);
	if (philos->info->max_number_of_meals > 0)
	{
		pthread_create(&eat_big_brother, NULL, &big_brother_eat, philos);
		pthread_detach(eat_big_brother);
	}
}
