/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:10:09 by fialexan          #+#    #+#             */
/*   Updated: 2023/02/08 12:37:27 by fialexan         ###   ########.fr       */
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

// Define Codes

# define FORK_CODE 1
# define EAT_CODE 2
# define SLEEP_CODE 3
# define THINK_CODE 4
# define DIED_CODE 5

// Define Messages

# define FORK_MESSAGE "has taken a fork\n"
# define EAT_MESSAGE "is eating\n"
# define SLEEP_MESSAGE "is sleeping\n"
# define THINK_MESSAGE "is thinking\n"
# define DIED_MESSAGE "died\n"

// Types

typedef struct s_table
{
	t_philo			*philo;
	pthread_mutex_t	*forks;
}	t_table;

/**
 * @brief Philosopher type as all the information for them to life.
 * 
 * @param thread
 * @param philo_num int
 * @param time_to_die int
 * @param time_to_eat int
 * @param time_to_sleep int
 * @param number_time_eat int
 * @param last_time_ate long long
 * @param max_times_eat int
 */
typedef struct s_philo
{
	int			thread_num;
	int			philo_num;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			number_time_eat;
	int			max_times_eat;
	long long	last_time_ate;
	pthread_t	thread;
}	t_philo;

// Philosophers

/**
 * @brief Gets the current time
 * 
 * @return long long int 
 */
long long	get_time_of_day(void);

// Parser

/**
 * @brief Parses 
 * 
 * @param ac int
 * @param av char **
 * @param phil t_philo
 * @param fork pthread_mutex_t
 * @return int 
 */
int			parser(int ac, char **av, t_philo **ph, pthread_mutex_t **fork);

/**
 * @brief Initializes all the mutexs for the forks.
 * 
 * @param forks pthread_mutex_t **
 * @param num int
 */
void		init_fork(pthread_mutex_t **forks, int num);

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
void		init_philos(t_philo **philo, char **argv, int argc);

// Util Functions

/**
 * @brief Receives a string and returns it in a form of int
 * 
 * @param str char *
 * @return int 
 */
int			ft_atoi(char *str);

// Free

/**
 * @brief Frees all the allocated memory of the philosophers
 * 
 * @param philo t_philo *
 * @param fork pthread_mutex_t *
 * @param num int
 * @return int 
 */
int			free_philosopher(t_philo *philo, pthread_mutex_t *fork, int num);

// Print Message

/**
 * @brief Prints a message with the form: 
 * ['time'] 'philo_number' 'message_type'
 * 
 * @param message_type 
 * @param time 
 * @param philo_number 
 */
void		print_message(int message_type, long long time, int philo_num);

#endif
