/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canibefii <canibefii@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:16:26 by fialexan          #+#    #+#             */
/*   Updated: 2023/05/23 15:17:13 by canibefii        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(char *str)
{
	int	number;
	int	signal;

	signal = 1;
	if (str[0] == '-')
		signal = -1;
	number = 0;
	while (*str != '\0' && (*str >= '0' && *str <= '9'))
	{
		number = number * 10 + (*str - '0');
		str++;
	}
	return (signal * number);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*un_s1;
	unsigned char	*un_s2;

	un_s1 = (unsigned char *)s1;
	un_s2 = (unsigned char *)s2;
	i = 0;
	while (un_s1[i] != '\0' && un_s2[i] != '\0' && un_s1[i] == un_s2[i])
				i++;
	return (un_s1[i] - un_s2[i]);
}
