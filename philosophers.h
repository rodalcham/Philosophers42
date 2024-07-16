/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez <rchavez@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:21:28 by rchavez           #+#    #+#             */
/*   Updated: 2024/07/16 11:39:13 by rchavez          ###   ########.fr       */
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
	int				forks[2];
	long			last_meal;
	long			params[6];
	pthread_mutex_t	*mtx;
	pthread_mutex_t	*stat;
}					t_philo;

// My time functions
long	c_time(void);
long	*s_time(void);
long	msleep(long time);

// Parsing
int		usage(void);
void	print_params(long params[5]);
int		parse(int argc, char **argv, t_philo p[]);

// My philo routine
int		*get_run(void);
void	*routine(void *p);
void	*keeper_routine(void	*philo);
int		print_msg(long p_nbr, char *msg, pthread_mutex_t *print);

// Utils
void	intro(void);
void	philo_init(long c_time, t_philo	philo[], int philo_nbr);
int		philo_start(pthread_t *t_nbr,  t_philo	philo[], int philo_nbr);
int		mtx_destroy(pthread_mutex_t *forks, pthread_mutex_t *stat, long philo_nbr);
int		mtx_init(pthread_mutex_t *forks, pthread_mutex_t *stat, t_philo philo[], int philo_nbr);

// Fancy intro
void	img1(void);
void	img2(void);
void	img3(void);
void	img4(void);
void	img5(void);

#endif