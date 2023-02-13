/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:10:09 by fialexan          #+#    #+#             */
/*   Updated: 2023/02/13 16:52:36 by fialexan         ###   ########.fr       */
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

/**
 * @brief Philosopher type as all the information for them to life.
 * 
 * @param philo_num int
 * @param time_to_die int
 * @param time_to_eat int
 * @param time_to_sleep int
 * @param number_time_eat int
 * @param last_time_ate long long
 * @param max_times_eat int
 * @param init_time long long
 * @param thread pthread_t
 * @param thread_num int
 * @param left_fork phread_mutex_t *
 * @param right_fork pthread_mutex_t *
 */
typedef struct s_philo
{
	int				thread_num;
	int				philo_num;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				number_time_eat;
	int				max_times_eat;
	int				is_dead;
	long long		last_time_ate;
	long long		init_time;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*message;
}	t_philo;

/**
 * @brief Table with all the philosophers the forks and the number
 *  of philosophers.
 *
 * @param philo t_philo *
 * @param forks pthread_mutex_t * 
 */
typedef struct s_table
{
	t_philo			*philo;
	pthread_mutex_t	*forks;
	int				philo_num;
}	t_table;

// Philosophers

/**
 * @brief Gets the current time
 * 
 * @return long long
 */
long long	get_time_of_day(void);

/**
 * @brief Get the time difference between the current time and the time given.
 * 
 * @param time long long
 * @return long long 
 */
long long	get_time_diff(long long time);

// Parser

/**
 * @brief Parses 
 * 
 * @param ac int
 * @param av char **
 * @param table t_table *
 * @return int 
 */
int			parser(int ac, char **av, t_table *table);

/**
 * @brief Attributes a left and right fork to each philosopher
 * 
 * @param table t_table *
 */
void		attribute_forks(t_table *table);

/**
 * @brief Initializes all the mutexs for the forks.
 * 
 * @param forks pthread_mutex_t **
 * @param num int
 */
void		init_fork(pthread_mutex_t **forks, int num);

/**
 * @brief Initializes all the mutexes in thhe philosopher.
 * 
 * @param philo t_philo *
 */
void		init_mutex(t_philo *philo);

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
 * @param table t_table *
 * @param num int
 * @return int 
 */
int			free_philosopher(t_table *table, int num);

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

// Dinner

/**
 * @brief Calls function for the philosophers eat, sleep  and think 
 * and verifies that they don't die.
 * 
 * @param args void *
 * @return void* 
 */
void		*dinner(void *args);

/**
 * @brief Receives a philosophers and makes it think.
 * 
 * @param philo t_philo *
 */
void		think_philo(t_philo *philo);

/**
 * @brief Receives a philosopher and makes it sleep for a set time. 
 * 
 * @param philo t_philo *
 */
void		sleep_philo(t_philo *philo);

/**
 * @brief Receives a philosopher, locks the left and right fork, makes it eat
 * for a set of time, them unlocks both forks.
 * 
 * @param philo t_philo *
 */
void		eat_philo(t_philo *philo);

/**
 * @brief Receives a philosopher and the function that called it, if it was
 * *eat_philo* and the philosophers as eaten enough times
 * 
 * @param philo 
 * @param call_function 
 * @return int 
 */
int			stop_dinner(t_philo *philo, int call_function);

#endif
