/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:38:18 by fialexan          #+#    #+#             */
/*   Updated: 2023/04/22 20:06:40 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

t_info	*parse_input(int argc, char **argv)
{
	t_info	*info;

	if (argc < 5 || argc > 6)
	{
		handle_error(WRONG_NUM_ARGS, -1);
		return (NULL);
	}
	info = init_info(argc, argv);
	if (info == NULL)
	{
		handle_error(WRONG_ARGS, -1);
		return (NULL);
	}
	info = init_forks(info);
	if (info == NULL)
	{
		free_info(info);
		handle_error(FORKS_INITIALIZATION, -1);
		return (NULL);
	}
	return (info);
}

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
