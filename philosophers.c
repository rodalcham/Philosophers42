/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez@student.42heilbronn.de <rchavez    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:21:16 by rchavez           #+#    #+#             */
/*   Updated: 2024/07/15 17:16:02 by rchavez@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philo			philo[PHILO_MAX + 1];
	pthread_mutex_t	forks[PHILO_MAX + 1];
	pthread_t		t_nbr[PHILO_MAX + 1];
	int	i;

	intro();
	if (parse(argc, argv, philo) < 0)
		return (usage());
	mtx_init(forks, philo, philo[0].params[0]);
	*s_time() = c_time();
	philo_init(*s_time(), philo, philo[0].params[0]);
	philo_start(&t_nbr[0], philo, philo[0].params[0]);
	if (pthread_create(&t_nbr[0], NULL, &keeper_routine, &philo))
		return (0);
	i = 0;
	while (i <= philo[0].params[0])
	{
		pthread_join(t_nbr[i], NULL);
		i++;
	}
	mtx_destroy(forks, philo[0].params[0]);
}
