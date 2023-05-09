/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:12:05 by fialexan          #+#    #+#             */
/*   Updated: 2023/05/09 15:47:58 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	free_info(t_info *info)
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
}
