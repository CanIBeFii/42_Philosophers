/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:24:48 by fialexan          #+#    #+#             */
/*   Updated: 2023/02/01 14:24:47 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philosopher	*philosophers;
	pthread_mutex_t	*forks;

	if (parser(argc, argv, &philosophers, &forks) == FAILURE)
		return (0);
	
	return (0);
}
