/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:21:02 by fialexan          #+#    #+#             */
/*   Updated: 2023/02/06 14:42:33 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_message(int message_type, long long int time, int philo_number)
{
	if (message_type == FORK_CODE)
		printf("[%d] %d %s", time, philo_number, FORK_MESSAGE);
	else if (message_type == EAT_CODE)
		printf("[%d] %d %s", time, philo_number, EAT_MESSAGE);
	else if (message_type == SLEEP_CODE)
		printf("[%d] %d %s", time, philo_number, SLEEP_MESSAGE);
	else if (message_type == THINK_CODE)
		printf("[%d] %d %s", time, philo_number, THINK_MESSAGE);
	else if (message_type == DIED_CODE)
		printf("[%d] %d %s", time, philo_number, DIED_MESSAGE);
	else
		printf("Message code unknow: %d\n", message_type);
}
