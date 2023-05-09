/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:38:18 by fialexan          #+#    #+#             */
/*   Updated: 2023/05/09 15:42:09 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	parse_input(t_info *info, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		handle_error(WRONG_NUM_ARGS, -1);
		return (0);
	}
	if (init_info(info, argc, argv) == 0)
	{
		handle_error(WRONG_ARGS, -1);
		return (0);
	}
	if (init_forks(info) == 0)
	{
		handle_error(FORKS_INITIALIZATION, -1);
		return (0);
	}
	return (1);
}
