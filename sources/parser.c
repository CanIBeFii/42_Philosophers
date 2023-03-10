/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:13:31 by fialexan          #+#    #+#             */
/*   Updated: 2023/02/15 11:23:29 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	parser(int ac, char **av, t_table *table)
{
	t_philo			*philo;
	pthread_mutex_t	*forks;

	if (ac != 5 && ac != 6)
	{
		printf("Error!\nUsage ./philosophers number_of_philosophers ");
		printf("time_to_die time_to_eat time_to_sleep ");
		printf("[number_of_times_each_philosopher_must_eat]\n");
		return (FAILURE);
	}
	table->philo_num = ft_atoi(av[1]);
	philo = malloc(sizeof(t_philo) * table->philo_num);
	if (philo == NULL)
		return (FAILURE);
	forks = malloc(sizeof(pthread_mutex_t) * table->philo_num);
	if (forks == NULL)
		return (FAILURE);
	pthread_mutex_init(&table->message, NULL);
	init_fork(&forks, table->philo_num);
	init_philos(&philo, av, ac, &table->message);
	table->philo = philo;
	table->forks = forks;
	attribute_forks(table);
	return (SUCCESS);
}

void	attribute_forks(t_table *table)
{
	int	iter;

	iter = 0;
	while (iter < table->philo_num - 1)
	{
		table->philo[iter].left_fork = &table->forks[iter];
		table->philo[iter].right_fork = &table->forks[iter + 1];
		iter++;
	}
	table->philo[iter].left_fork = &table->forks[iter];
	table->philo[iter].right_fork = &table->forks[0];
}

void	init_philos(t_philo **p, char **argv, int argc, pthread_mutex_t *m)
{
	int			philo_number;
	int			iter;
	t_philo		*philosopher;

	philo_number = ft_atoi(argv[1]);
	iter = 0;
	philosopher = *p;
	while (iter < philo_number)
	{
		philosopher[iter].philo_id = iter;
		philosopher[iter].time_to_die = ft_atoi(argv[2]);
		philosopher[iter].time_to_eat = ft_atoi(argv[3]);
		philosopher[iter].time_to_sleep = ft_atoi(argv[4]);
		philosopher[iter].number_time_eat = 0;
		philosopher[iter].last_time_ate = 0;
		philosopher[iter].thread_num = 0;
		philosopher[iter].is_dead = 0;
		philosopher[iter].max_philo = philo_number;
		philosopher[iter].message = m;
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
