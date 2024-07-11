/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez@student.42heilbronn.de <rchavez    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 21:44:10 by rchavez@stu       #+#    #+#             */
/*   Updated: 2024/07/11 07:47:34 by rchavez@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *philo)
{
	t_philo p = *(t_philo *)philo;

	if	(!p.nbr % 2)
		msleep(p.params[4]);
	while (1)
	{
		pthread_mutex_lock(&p.mtx[p.forks[0]]);
		pthread_mutex_lock(&p.mtx[p.forks[1]]);
		printf("Philo %i is eating\n", p.nbr);
		pthread_mutex_unlock(&p.mtx[p.forks[1]]);
		pthread_mutex_unlock(&p.mtx[p.forks[0]]);
	}
	return (NULL);
}
