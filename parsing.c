/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez <rchavez@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 08:05:31 by rchavez           #+#    #+#             */
/*   Updated: 2024/07/16 10:44:55 by rchavez          ###   ########.fr       */
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

void	arr_cpy(long dst[], long src[], int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		dst[i] = src[i];
	}
}

int	parse(int argc, char **argv, t_philo p[])
{
	int	i;

	if (argc < 5 || argc > 6)
		return (-1);
	p[0].params[0] = ft_atoli(argv[1]);
	p[0].params[1] = ft_atoli(argv[2]);
	p[0].params[2] = ft_atoli(argv[3]);
	p[0].params[3] = ft_atoli(argv[4]);
	p[0].params[4] = ft_atoli(argv[5]);
	if (p[0].params[0] > PHILO_MAX || p[0].params[0] < 2)
		return (-1);
	if (p[0].params[1] < 1)
		return (-1);
	if (p[0].params[2] < 1 || p[0].params[2] > p[0].params[1])
		return (-1);
	if (p[0].params[3] < 1 || p[0].params[3] + p[0].params[2] > p[0].params[1])
		return (-1);
	if (p[0].params[4] < 1 && argv[5])
		return (-1);
	if (!argv[5])
		p[0].params[4] = -1;
	if (p[0].params[0] % 2 == 0)
		p[0].params[5] = 0;
	else
		p[0].params[5] = (2 * p[0].params[2] - p[0].params[3]);
	i = 0;
	while (++i <= p[0].params[0])
		arr_cpy(p[i].params, p[0].params, 6);
	print_params(p[0].params);
	return (0);
}
