/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez@student.42heilbronn.de <rchavez    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:21:16 by rchavez           #+#    #+#             */
/*   Updated: 2024/07/11 07:35:36 by rchavez@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(void)
{
	t_philo			philo[PHILO_MAX + 1];
	pthread_mutex_t	forks[PHILO_MAX + 1];
	pthread_t		t_nbr[PHILO_MAX + 1];

	// pthread_mutex_init(printf, NULL);
	intro();
	philo[0].params[0] = 42;
	philo[0].params[1] = 100;
	philo[0].params[2] = 100;
	philo[0].params[3] = 100;
	philo[0].params[4] = 5;
	mtx_init(forks, philo, philo[0].params[0]);
	*s_time() = c_time();
	philo_init(*s_time(), philo, philo[0].params[0]);
	philo_start(t_nbr, philo, philo[0].params[0]);
	mtx_destroy(forks, philo[0].params[0]);
	// pthread_mutex_destroy(&printf);
}