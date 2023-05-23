/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canibefii <canibefii@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:25:24 by canibefii         #+#    #+#             */
/*   Updated: 2023/05/23 15:11:43 by canibefii        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	print_message(t_philo *philo, char *str)
{
	if (check_end_dinner(philo) == 1)
		return ;
	pthread_mutex_lock(philo->info->message);
	if (ft_strcmp(str, FORK_TAKEN) == 0)
	{
		printf("%lld %d %s\n", time_diff(philo->start_time), philo->id, str);
		printf("%lld %d %s\n", time_diff(philo->start_time), philo->id, str);
	}
	else 
		printf("%lld %d %s\n", time_diff(philo->start_time), philo->id, str);
	pthread_mutex_unlock(philo->info->message);
}