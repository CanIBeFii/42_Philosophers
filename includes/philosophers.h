/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:33:37 by fialexan          #+#    #+#             */
/*   Updated: 2023/05/11 15:55:33 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>

// DEFINES

typedef pthread_mutex_t	t_mutex;
typedef pthread_t		t_thread;

typedef struct s_info
{
	int		total_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		max_number_of_meals;
	int		*is_fork_used;
	t_mutex	*message;
	t_mutex	*forks;
	t_mutex	*death;
	int		philo_died;
}	t_info;

typedef struct s_philo
{
	int			id;
	t_thread	thread;
	t_mutex		*left_fork;
	t_mutex		*right_fork;
	int			*l_fork_state;
	int			*r_fork_state;
	int			num_of_meals;
	long long	last_meal;
	long long	start_time;
	t_info		*info;
}	t_philo;

// ERROR CODES

# define WRONG_NUM_ARGS 10
# define WRONG_ARGS 20
# define FORKS_INITIALIZATION 30
# define PHILOS_INITIALIZATION 40

# define SLEEP_CODE 11
# define EAT_CODE 21
# define THINK_CODE 31
# define DEATH_CODE 41
# define FORK_CODE 51

// PHILOSOPHERS.C

void		start_dinner(t_info info, t_philo *philos);

// PARSER.C

int			parse_input(t_info *info, int argc, char **argv);

// INITIALIZATION.C

int			init_info(t_info *info, int argc, char **argv);

int			init_forks(t_info *info);

t_philo		*init_philos(t_info info);

// ERROR_HANDLING.C

int			handle_error(int error_code, int return_value);

// FREE.C

void		free_info(t_info *info);

// UTIL_FUNCTIONS.C

int			ft_atoi(char *str);

// TIME.C

long long	get_time(void);

long long	time_diff(long long time);

// DINNER.C

void		*dinner(void *args);

void		*one_philo(void *args);

void		*distribute_dinner(void *args);

int			check_end_dinner(t_philo *philo);

int			forks_are_free(t_philo *philo);

// DINNER_ACTIONS.C

int			philo_eat(t_philo *philo);

int			philo_sleep(t_philo *philo);

int			philo_think(t_philo *philo);

int			philo_take_forks(t_philo *philo);

void		lock_forks(t_philo *philo);

// MESSSAGE.C

void		print_message(t_philo *philo, int message_code);

#endif
