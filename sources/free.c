/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:12:05 by fialexan          #+#    #+#             */
/*   Updated: 2023/04/17 19:25:11 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_info(t_info *info)
{
	if (info != NULL)
	{
		if (info->forks != NULL)
		{
			pthread_mutex_destroy(info->forks);
			free(info->forks);
		}
		if (info->message != NULL)
		{
			pthread_mutex_destroy(info->message);
			free(info->message);
		}
		if (info->death != NULL)
		{
			pthread_mutex_destroy(info->death);
			free(info->death);
		}
		free(info);
	}
}
