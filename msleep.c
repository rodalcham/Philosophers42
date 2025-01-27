/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msleep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez <rchavez@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:33:02 by rchavez           #+#    #+#             */
/*   Updated: 2024/07/16 12:56:51 by rchavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	c_time(void)
{
	struct timeval	start_time;

	gettimeofday(&start_time, NULL);
	return (start_time.tv_sec * 1000 + start_time.tv_usec / 1000);
}

long	*s_time(void)
{
	static long	start = 0;

	return (&start);
}

long	msleep(long time)
{
	long	start;
	long	curr;

	start = c_time();
	curr = c_time() - start;
	while (curr < time)
	{
		curr = c_time() - start;
		usleep(50);
	}
	return (0);
}
