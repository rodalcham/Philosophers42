/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez <rchavez@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:21:16 by rchavez           #+#    #+#             */
/*   Updated: 2024/07/11 08:38:58 by rchavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philo			philo[PHILO_MAX + 1];
	pthread_mutex_t	forks[PHILO_MAX + 1];
	pthread_t		t_nbr[PHILO_MAX + 1];

	intro();
	if (parse(argc, argv, philo) < 0)
		return (usage());
	mtx_init(forks, philo, philo[0].params[0]);
	*s_time() = c_time();
	philo_init(*s_time(), philo, philo[0].params[0]);
	philo_start(t_nbr, philo, philo[0].params[0]);
	mtx_destroy(forks, philo[0].params[0]);
}
