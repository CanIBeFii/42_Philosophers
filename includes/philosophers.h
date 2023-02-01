/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:10:09 by fialexan          #+#    #+#             */
/*   Updated: 2023/02/01 14:16:16 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

// Includes

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

// Defines

# define FAILURE 0
# define SUCCESS 1

// Types

/**
 * @brief Philosopher type as all the information for them to life.
 * 
 * @param philo_number int
 * @param time_to_die int
 * @param time_to_eat int
 * @param time_to_sleep int
 * @param number_time_eat int
 * @param max_times_eat int
 */
typedef struct s_philosopher
{
	int			philo_number;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			number_time_eat;
	int			max_times_eat;
}	t_philosopher;

// Parser

/**
 * @brief 
 * 
 * @param ac 
 * @param av 
 * @param phil 
 * @param fork 
 * @return int 
 */
int		parser(int ac, char **av, t_philosopher **phil, pthread_mutex_t **fork);

/**
 * @brief Initializes all the philosophers with their information about:
 * - philosopher number\n
 * - time to die\n
 * - time to eat\n
 * - time to sleep\n
 * - maximum time to eat
 * 
 * @param philo t_philosopher **
 * @param argv char **
 * @param argc int
 */
void	init_philos(t_philosopher **philo, char **argv, int argc);

// Util Functions

/**
 * @brief Receives a string and returns it in a form of int
 * 
 * @param str char *
 * @return int 
 */
int		ft_atoi(char *str);

#endif
