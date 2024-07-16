/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine->c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez@student.42heilbronn.de <rchavez    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 21:44:10 by rchavez@stu       #+#    #+#             */
/*   Updated: 2024/07/15 18:49:34 by rchavez@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//	p.params[0] = philo nbr
//	p.params[1] = time to die
//	p.params[2] = time to eat
//	p.params[3] = time to sleep
//	p.params[4] = meals left
//	p.params[5] = time to think = time to eat * 2 - time to sleep

int	*get_run(void)
{
	static int	run = 1;

	return (&run);
}

int	print_msg(long p_nbr, char *msg, pthread_mutex_t *print)
{
	int	i;

	i = 1;
	pthread_mutex_lock(print);
	if (*get_run())
	{
		i = 0;
		printf("%li %li %s\n", c_time() - *s_time(), p_nbr, msg);
	}
	pthread_mutex_unlock(print);
	return (i);
}

void	*routine(void *philo)
{
	t_philo *p = (t_philo *)philo;

	if	(p->nbr % 2 == 0 || p->nbr == p->params[0])
	{
		print_msg(p->nbr, "is sleeping", &p->mtx[0]);
		msleep(p->params[2]);
	}
	while (1)
	{
		pthread_mutex_lock(&p->mtx[p->forks[0]]);
		print_msg(p->nbr, "has taken a fork", &p->mtx[0]);
		pthread_mutex_lock(&p->mtx[p->forks[1]]);
		print_msg(p->nbr, "has taken a fork", &p->mtx[0]);
		print_msg(p->nbr, "is eating", &p->mtx[0]);
		p->last_meal = c_time();
		msleep(p->params[2]);
		print_msg(p->nbr, "is sleeping", &p->mtx[0]);
		pthread_mutex_unlock(&p->mtx[p->forks[1]]);
		pthread_mutex_unlock(&p->mtx[p->forks[0]]);
		msleep(p->params[3]);
		if (print_msg(p->nbr, "is thinking", &p->mtx[0]))
			break ;
		msleep(p->params[5]);
		if (p->params[4] > 0)
			p->params[4]--;
		if (p->params[4] == 0)
			break ;
	}
	return (NULL);
}
