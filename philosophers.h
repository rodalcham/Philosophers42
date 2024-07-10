/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez@student.42heilbronn.de <rchavez    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:21:28 by rchavez           #+#    #+#             */
/*   Updated: 2024/07/10 21:57:27 by rchavez@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_C
# define PHILOSOPHERS_C

# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

# define PHILO_MAX 200

// My philo struct
typedef struct	s_philo
{
	int				nbr;
	long			last_meal;
	int				meals;
	int				forks[2];
	pthread_mutex_t	*mtx;
}					t_philo;

// My time functions
long	c_time(void);
long	*s_time(void);
long	msleep(long time);

// My philo routine
void	*routine(void *p);

// Fancy intro
void	img1(void);
void	img2(void);
void	img3(void);
void	img4(void);
void	img5(void);

#endif