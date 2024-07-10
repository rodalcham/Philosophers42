/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez@student.42heilbronn.de <rchavez    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:21:16 by rchavez           #+#    #+#             */
/*   Updated: 2024/07/10 22:07:35 by rchavez@stu      ###   ########.fr       */
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
		philo->last_meal = c_time;
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

int	mtx_destroy(pthread_mutex_t *forks, int philo_nbr)
{
	int	i;

	i = -1;
	while (++i <= philo_nbr)
	{
		if (pthread_mutex_init(&forks[i], NULL) < 0)
			return (-1);
	}
	return (0);
}
int	philo_start(pthread_t t_nbr[],  t_philo	philo[], int philo_nbr)
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

int	main(void)
{
	t_philo			philo[PHILO_MAX + 1];
	pthread_mutex_t	forks[PHILO_MAX + 1];
	pthread_t		t_nbr[PHILO_MAX + 1];

	// pthread_mutex_init(printf, NULL);
	intro();
	mtx_init(forks, philo, 42);
	*s_time() = c_time();
	philo_init(*s_time(), philo, 42);
	philo_start(t_nbr, philo, 42);
	mtx_destroy(forks, 42);
	// pthread_mutex_destroy(&printf);
}