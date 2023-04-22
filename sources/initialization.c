/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 20:04:00 by filipe            #+#    #+#             */
/*   Updated: 2023/04/22 20:21:52 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

t_info	*init_forks(t_info *info)
{
	int	iter;

	iter = 0;
	info->message = malloc(sizeof(t_mutex));
	if (info->message == NULL)
		return (NULL);
	pthread_mutex_init(info->message, NULL);
	info->death = malloc(sizeof(t_mutex));
	if (info->death == NULL)
		return (NULL);
	pthread_mutex_init(info->death, NULL);
	info->forks = malloc(sizeof(t_mutex) * info->total_philos);
	if (info->forks == NULL)
		return (NULL);
	while (iter < info->total_philos)
	{
		pthread_mutex_int(&info->forks[iter], NULL);
		iter++;
	}
	return (info);
}

t_info	*init_info(int argc, char **argv)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (info == NULL)
		return (NULL);
	info->total_philos = ft_atoi(argv[1], 0);
	info->time_to_die = ft_atoi(argv[2], 0);
	info->time_to_eat = ft_atoi(argv[3], 0);
	info->time_to_sleep = ft_atoi(argv[4], 0);
	if (argc == 6)
		info->max_number_of_meals = ft_atoi(argv[5], 0);
	else
		info->max_number_of_meals = -2;
	if (info->total_philos < 1 || info->time_to_die < 1 || info->time_to_eat < 1
		|| info->time_to_sleep < 1 || info->max_number_of_meals < -1)
	{
		free(info);
		return (NULL);
	}	
	return (info);
}

t_philo	*init_philos(t_info *info)
{
	t_philo	*philos;
	int			iter;

	iter = 0;
	philos = malloc(sizeof(t_philo) * (info->total_philos + 1));
	if (philos == NULL)
	{
		handle_error
	}
		return (NULL);
	while (iter < info->total_philos)
	{
		philos[iter].id = iter + 1;
		philos[iter].left_fork = &info->forks[iter];
		philos[iter].right_fork = &info->forks[(iter + 1) % info->total_philos];
		philos[iter].num_of_meals = info->max_number_of_meals;
		philos[iter].last_meal = 0;
		philos[iter].start_time = 0;
		philos[iter].info = info;
		iter++;
	}
	return (philos);
}
