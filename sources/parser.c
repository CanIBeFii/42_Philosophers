/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:13:31 by fialexan          #+#    #+#             */
/*   Updated: 2023/02/06 13:48:34 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	parser(int ac, char **av, t_philo **phil, pthread_mutex_t **fork)
{
	int	arg_num;

	if (ac != 5 && ac != 6)
	{
		printf("Error!\nUsage ./philosophers number_of_philosophers ");
		printf("time_to_die time_to_eat time_to_sleep ");
		printf("[number_of_times_each_philosopher_must_eat]\n");
		return (FAILURE);
	}
	arg_num = ft_atoi(av[1]);
	*phil = malloc(sizeof(t_philo) * arg_num);
	if (*phil == NULL)
		return (FAILURE);
	*fork = malloc(sizeof(pthread_mutex_t) * arg_num);
	if (*fork == NULL)
		return (FAILURE);
	init_fork(fork, arg_num);
	init_philos(phil, av, ac);
	return (SUCCESS);
}

void	init_philos(t_philo **philo, char **argv, int argc)
{
	int			philo_number;
	int			iter;
	t_philo		*philosopher;

	philo_number = ft_atoi(argv[1]);
	iter = 0;
	philosopher = *philo;
	while (iter < philo_number)
	{
		philosopher[iter].philo_number = iter;
		philosopher[iter].time_to_die = ft_atoi(argv[2]);
		philosopher[iter].time_to_eat = ft_atoi(argv[3]);
		philosopher[iter].time_to_sleep = ft_atoi(argv[4]);
		philosopher[iter].number_time_eat = 0;
		if (argc == 6)
			philosopher[iter].max_times_eat = ft_atoi(argv[5]);
		else
			philosopher[iter].max_times_eat = -1;
		iter++;
	}
}

void	init_fork(pthread_mutex_t **forks, int num)
{
	int				iter;
	pthread_mutex_t	*fork;

	fork = *forks;
	iter = 0;
	while (iter < num)
	{
		pthread_mutex_init(&fork[iter], NULL);
		iter++;
	}
}
