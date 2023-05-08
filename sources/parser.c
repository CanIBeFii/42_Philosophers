/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:38:18 by fialexan          #+#    #+#             */
/*   Updated: 2023/05/08 11:26:34 by fialexan         ###   ########.fr       */
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
		handle_error(FORKS_INITIALIZATION, -1);
		return (NULL);
	}
	return (info);
}
