/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:38:18 by fialexan          #+#    #+#             */
/*   Updated: 2023/04/17 19:11:56 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	parse_input(int argc, char **argv)
{
	t_info	*info;

	if (argc < 5 || argc > 6)
		return (handle_error(WRONG_NUM_ARGS, -1));
	info = init_info(argc, argv);
	if (info == NULL)
		return (handle_error(WRONG_ARGS, -1));
	
	return (0);
}

t_info	*init_info(int argc, char **argv)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (info == NULL)
		return (NULL);
	info->total_philos = ft_atoi(argv[1], 0);
	info->time_to_die = ft_atoi(argv[2], 0);
	info->time_to_eat = ft_atoi(argv[3], 0);
	info->time_to_sleep = ft_atoi(argv[4], 0);
	if (argc == 6)
		info->max_number_of_meals = ft_atoi(argv[5], 0);
	else
		info->max_number_of_meals = -2;
	if (info->total_philos < 1 || info->time_to_die < 1 || info->time_to_eat < 1
		|| info->time_to_sleep < 1 || info->max_number_of_meals < -1)
	{
		free(info);
		return (NULL);
	}
	
	return (info);
}

t
int	ft_atoi(char *str, int i)
{
	int	number;
	int	signal;

	signal = 1;
	number = 0;
	if (check_is_number(str) == 0)
		return (-1);
	while (str[i] != '\0' && (str[i] == ' ' || (str[i] > 8 && str[i] < 14)))
		i++;
	while (str[i] != '\0' && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i + 1] == '-' || str[i + 1] == '+')
			return (0);
		if (str[i] == '-')
			signal *= -1;
		i++;
	}
	while (48 <= str[i] && str[i] <= 57)
	{
		number *= 10;
		number += str[i] - '0';
		i++;
	}
	return (signal * number);
}

int	check_is_number(char *str)
{
	int	iter;

	iter = 0;
	if (str[iter] == '-')
		iter++;
	while (str[iter] != '\0')
	{
		if ('9' < str[iter] || str[iter] < '0')
			return (0);
		iter++;
	}
	return (1);
}
