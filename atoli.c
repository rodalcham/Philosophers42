/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoli.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez <rchavez@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:15:13 by rchavez           #+#    #+#             */
/*   Updated: 2024/07/16 14:16:02 by rchavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_isdigit(int c)
{
	if (c > '9' || c < '0')
		return (0);
	return (1);
}

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

long	ft_atoli(const char *str)
{
	size_t		i;
	long int	x;
	int			min;

	i = 0;
	x = 0;
	min = 0;
	if (!str)
		return (0);
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			min++;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		x *= 10;
		x += str[i++] - '0';
	}
	if (min > 0)
		x *= -1;
	return (x);
}
