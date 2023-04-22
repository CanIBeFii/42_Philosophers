/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:33:37 by fialexan          #+#    #+#             */
/*   Updated: 2023/04/22 20:25:29 by filipe           ###   ########.fr       */
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
}	t_info;

typedef struct s_philo
{
	int			id;
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

// PARSER.C

t_info	*parse_input(int argc, char **argv);

int		ft_atoi(char *str, int i);

int		check_is_number(char *str);

// INITIALIZATION.C

t_info	*init_info(int argc, char **argv);

t_info	*init_forks(t_info *info);

t_philo	*init_philo(t_info *info);

// ERROR_HANDLING.C

int		handle_error(int error_code, int return_value);

// FREE.C

void	free_info(t_info *info);

#endif
