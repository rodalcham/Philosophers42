/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez@student.42heilbronn.de <rchavez    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 07:16:37 by rchavez@stu       #+#    #+#             */
/*   Updated: 2024/07/15 16:08:51 by rchavez@stu      ###   ########.fr       */
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
		philo[i].meals = 0;
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

int	mtx_init(pthread_mutex_t *forks, t_philo philo[], int philo_nbr)
{
	int	i;

	i = -1;
	while (++i <= philo_nbr)
	{
		if (pthread_mutex_init(&forks[i], NULL) < 0)
			return (-1);
		philo[i].mtx = forks;
	}
	return (0);
}

int	mtx_destroy(pthread_mutex_t *forks, long philo_nbr)
{
	int	i;

	i = -1;
	while (++i <= philo_nbr)
	{
		if (pthread_mutex_destroy(&forks[i]) < 0)
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
