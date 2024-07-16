/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez <rchavez@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 07:16:37 by rchavez@stu       #+#    #+#             */
/*   Updated: 2024/07/16 13:18:50 by rchavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	intro(void)
{
	*s_time() = c_time();
	img1();
	msleep(100);
	img2();
	msleep(100);
	img3();
	msleep(100);
	img4();
	msleep(100);
	img5();
	msleep(300);
}

void	philo_init(long c_time, t_philo	philo[], int philo_nbr)
{
	int	i;

	i = 0;
	while (++i <= philo_nbr)
	{
		philo[i].nbr = i;
		philo[i].last_meal = c_time;
		if (i % 2)
		{
			philo[i].forks[0] = i;
			if (i > 1)
				philo[i].forks[1] = i - 1;
			else
				philo[i].forks[1] = philo_nbr;
		}
		else
		{
			if (i > 1)
				philo[i].forks[0] = i - 1;
			else
				philo[i].forks[0] = philo_nbr;
			philo[i].forks[1] = i;
		}
	}
}

int	mtx_init(pthread_mutex_t *forks,
	pthread_mutex_t *stat, t_philo philo[], int philo_nbr)
{
	int	i;

	i = -1;
	while (++i <= philo_nbr)
	{
		if (pthread_mutex_init(&stat[i], NULL) < 0)
			return (-1);
		if (pthread_mutex_init(&forks[i], NULL) < 0)
			return (-1);
		philo[i].mtx = forks;
		philo[i].stat = &stat[i];
	}
	return (0);
}

int	mtx_destroy(pthread_mutex_t *forks, pthread_mutex_t *stat, long philo_nbr)
{
	int	i;

	i = -1;
	while (++i <= philo_nbr)
	{
		if (pthread_mutex_destroy(&forks[i]) < 0)
			return (-1);
		if (pthread_mutex_destroy(&stat[i]) < 0)
			return (-1);
	}
	return (0);
}

int	philo_start(pthread_t *t_nbr, t_philo philo[], int philo_nbr)
{
	int	i;

	i = 0;
	while (++i <= philo_nbr)
	{
		if (pthread_create(&t_nbr[i], NULL, &routine, &philo[i]) < 0)
			return (-1);
	}
	return (0);
}
