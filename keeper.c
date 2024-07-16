/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keeper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez <rchavez@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:37:21 by rchavez@stu       #+#    #+#             */
/*   Updated: 2024/07/16 10:24:26 by rchavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*keeper_routine(void	*philo)
{
	t_philo	*p;
	int		i;
	int		alive;

	p = (t_philo *)philo;
	alive = 1;
	while (alive)
	{
		alive = 0;
		i = 0;
		while (++i <= p[0].params[0])
		{
			if (p[i].params[4])
				alive++;
			if (c_time() - p[i].last_meal >= p[0].params[1] && p[i].params[4] != 0)
			{
				pthread_mutex_lock(&p[0].mtx[0]);
				printf("%li %i \033[1m\033[31mdied\033[0m\n\n", c_time() - *s_time(), i);
				*get_run() = 0;
				pthread_mutex_unlock(&p[0].mtx[0]);
				return (0);
			}
		}
	}
	return (NULL);
}
