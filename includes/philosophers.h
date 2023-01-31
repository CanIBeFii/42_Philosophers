/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:10:09 by fialexan          #+#    #+#             */
/*   Updated: 2023/01/31 18:17:52 by fialexan         ###   ########.fr       */
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

// Types

/**
 * @brief Fork for the philosophers to eat.
 * 
 * @param fork_number int
 * @param mutex pthread_mutex_t
 */
typedef struct s_fork
{
	int			fork_number;
	pthread_mutex_t		mutex;
}	t_fork;

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

#endif
