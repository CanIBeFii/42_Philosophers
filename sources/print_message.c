/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:21:02 by fialexan          #+#    #+#             */
/*   Updated: 2023/02/08 11:31:13 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_message(int message_type, long long time, int philo_num)
{
	if (message_type == FORK_CODE)
		printf("[%lld] %d %s", time, philo_num, FORK_MESSAGE);
	else if (message_type == EAT_CODE)
		printf("[%lld] %d %s", time, philo_num, EAT_MESSAGE);
	else if (message_type == SLEEP_CODE)
		printf("[%lld] %d %s", time, philo_num, SLEEP_MESSAGE);
	else if (message_type == THINK_CODE)
		printf("[%lld] %d %s", time, philo_num, THINK_MESSAGE);
	else if (message_type == DIED_CODE)
		printf("[%lld] %d %s", time, philo_num, DIED_MESSAGE);
	else
		printf("Message code unknow: %d\n", message_type);
}
