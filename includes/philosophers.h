/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:33:37 by fialexan          #+#    #+#             */
/*   Updated: 2023/05/10 16:10:31 by fialexan         ###   ########.fr       */
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

int			check_end_dinner(t_philo *philo);

// DINNER_ACTIONS.C

int			philo_eat(t_philo *philo);

int			philo_sleep(t_philo *philo);

int			philo_think(t_philo *philo);

int			philo_take_forks(t_philo *philo);

#endif
