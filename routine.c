/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez <rchavez@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 21:44:10 by rchavez@stu       #+#    #+#             */
/*   Updated: 2024/07/11 10:36:27 by rchavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//	p.params[0] = philo nbr
//	p.params[1] = time to die
//	p.params[2] = time to eat
//	p.params[3] = time to sleep
//	p.params[4] = meals left

void	*routine(void *philo)
{
	t_philo p = *(t_philo *)philo;

	if	(!p.nbr % 2)
		msleep(p.params[4]);
	while (1)
	{
		if (p.nbr == p.params[0] && p.nbr % 2)
			pthread_mutex_lock(&p.mtx[p.forks[1]]);
		pthread_mutex_lock(&p.mtx[p.forks[0]]);
		pthread_mutex_lock(&p.mtx[p.forks[1]]);
		printf("Philo %i is eating\n", p.nbr);
		msleep(p.params[2]);
		printf("Philo %i is sleeping\n", p.nbr);
		msleep(p.params[3]);
		pthread_mutex_unlock(&p.mtx[p.forks[1]]);
		pthread_mutex_unlock(&p.mtx[p.forks[0]]);
		if (p.nbr == p.params[0] && p.nbr % 2)
			pthread_mutex_unlock(&p.mtx[p.forks[1]]);
	}
	return (NULL);
}
