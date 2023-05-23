/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canibefii <canibefii@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:33:37 by fialexan          #+#    #+#             */
/*   Updated: 2023/05/23 15:18:41 by canibefii        ###   ########.fr       */
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
	int		all_eaten;
	t_mutex	*eat;
	t_mutex	*message;
	t_mutex	*forks;
	t_mutex	*time;
	t_mutex	*death;
	int		philo_died;
}	t_info;

typedef struct s_philo
{
	int			id;
	t_thread	thread;
	t_mutex		*left_fork;
	t_mutex		*right_fork;
	t_mutex		*time;
	t_mutex		*eat;
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

# define FORK_TAKEN "has taken a fork\n"
# define EATING "is eating\n"
# define SLEEPING "is sleeping\n"
# define THINKING "is thinking\n"
# define DIED "died\n"

// PHILOSOPHERS.C

void		start_dinner(t_info info, t_philo *philos);

void		start_big_brother(t_philo *philos);

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

int			ft_strcmp(const char *s1, const char *s2);

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

void		sleep_checker(t_philo *philo, int total_sleep_time);

// MESSSAGE.C

void		print_message(t_philo *philo, char *str);

// BIG_BROTHER.C

void		*big_brother_eat(void *args);

int			philos_finnish_eating(t_philo *philos);

void		*big_brother_death(void *args);

void		kill_philo(t_philo *philo);

#endif
