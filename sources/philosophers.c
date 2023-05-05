/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:30:33 by fialexan          #+#    #+#             */
/*   Updated: 2023/05/05 12:43:23 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_info	*info;
	t_philo	*philos;

	info = parse_input(argc, argv);
	if (info == NULL)
		return (1);
	philos = init_philos(info);
	if (philos == NULL)
	{
		free_info(info);
		return (1);
	}
	return (0);
}