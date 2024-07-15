/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keeper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez@student.42heilbronn.de <rchavez    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:37:21 by rchavez@stu       #+#    #+#             */
/*   Updated: 2024/07/15 18:58:16 by rchavez@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*keeper_routine(void	*philo)
{
	t_philo	*p;
	int		i;

	p = (t_philo *)philo;
	while (1)
	{
		i = 0;
		while (++i <= p[0].params[0])
		{
			if (c_time() - p[i].last_meal >= p[0].params[1])
			{
				// printf("Time since last meal: %li\nTime to die: %li\n", p[i].last_meal - c_time(), p[0].params[1]);
				pthread_mutex_lock(&p[0].mtx[0]);
				printf("%li %i died\n", c_time() - *s_time(), i);
				return (0);
			}
		}
	}
}