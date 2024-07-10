/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez <rchavez@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:33:02 by rchavez           #+#    #+#             */
/*   Updated: 2024/07/10 17:06:17 by rchavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	s_time(void)
{
	static	struct timeval start_time = {0, 0};

	if (start_time.tv_sec == 0)
		gettimeofday(&start_time, NULL);
	return (start_time.tv_sec * 1000 + start_time.tv_usec/1000);
}

long	ft_usleep(size_t time)
{
	static struct timeval
}
