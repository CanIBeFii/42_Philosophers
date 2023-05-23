/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 20:04:00 by filipe            #+#    #+#             */
/*   Updated: 2023/05/23 18:26:00 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	init_forks(t_info *info)
{
	int	iter;

	iter = 0;
	info->message = malloc(sizeof(t_mutex));
	info->death = malloc(sizeof(t_mutex));
	info->forks = malloc(sizeof(t_mutex) * info->total_philos);
	info->eat = malloc(sizeof(t_mutex) * info->total_philos);
	info->time = malloc(sizeof(t_mutex) * info->total_philos);
	if (info->death == NULL || info->message == NULL || info->forks == NULL
		|| info->eat == NULL || info->time == NULL)
	{
		free_info(info);
		return (0);
	}
	pthread_mutex_init(info->message, NULL);
	pthread_mutex_init(info->death, NULL);
	while (iter < info->total_philos)
	{
		pthread_mutex_init(&info->forks[iter], NULL);
		pthread_mutex_init(&info->eat[iter], NULL);
		pthread_mutex_init(&info->time[iter], NULL);
		iter++;
	}
	return (1);
}

int	init_info(t_info *info, int argc, char **argv)
{
	info->total_philos = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->philo_died = 0;
	info->all_eaten = 0;
	if (argc == 6)
		info->max_number_of_meals = ft_atoi(argv[5]);
	else
		info->max_number_of_meals = -2;
	if (info->total_philos < 1 || info->time_to_die < 1 || info->time_to_eat < 1
		|| info->time_to_sleep < 1 || info->max_number_of_meals == -1)
		return (0);
	return (1);
}

t_philo	*init_philos(t_info info)
{
	t_philo	*philos;
	int		iter;

	iter = 0;
	philos = malloc(sizeof(t_philo) * (info.total_philos));
	if (philos == NULL)
	{
		handle_error(PHILOS_INITIALIZATION, -1);
		return (NULL);
	}
	while (iter < info.total_philos)
	{
		philos[iter].id = iter + 1;
		philos[iter].left_fork = &info.forks[iter];
		philos[iter].right_fork = &info.forks[(iter + 1) % info.total_philos];
		philos[iter].time = &info.time[iter];
		philos[iter].eat = &info.eat[iter];
		philos[iter].num_of_meals = info.max_number_of_meals;
		philos[iter].last_meal = 0;
		philos[iter].start_time = 0;
		iter++;
	}
	return (philos);
}
