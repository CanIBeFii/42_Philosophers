/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 19:44:53 by filipe            #+#    #+#             */
/*   Updated: 2023/04/22 20:23:59 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	handle_error(int error_type, int return_value)
{
	if (error_type == WRONG_NUM_ARGS)
		printf("Wrong number of arguments\n");
	else if (error_type == WRONG_ARGS)
		printf("Arguments must be positive integers\n");
	else if (error_type == FORKS_INITIALIZATION)
		printf("Error while initializing forks\n");
	else if (error_type == PHILOS_INITIALIZATION)
		printf("Error while initializing philos\n");
	return (return_value);
}
