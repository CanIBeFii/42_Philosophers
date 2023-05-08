/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:50:41 by fialexan          #+#    #+#             */
/*   Updated: 2023/05/08 12:04:43 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

long long	get_time(void)
{
	struct timeval	time;
	long long		miliseconds;

	gettimeofday(&time, NULL);
	miliseconds = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (miliseconds);
}

long long	time_diff(long long time)
{
	return (get_time() - time);
}
