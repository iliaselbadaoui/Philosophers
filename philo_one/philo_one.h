/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:07:25 by ielbadao          #+#    #+#             */
/*   Updated: 2021/01/14 12:54:15 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

pthread_mutex_t	g_mutex;
int				*g_forks;
int				*g_philos;
int				g_philo_num;
int				g_time_to_eat;
int				g_time_to_sleep;
int				g_time_to_die;
int				g_number_of_times_of_eat;

pthread_t		create_philo(void *(func(void *arg)), int *id);
void			init_forks(void);
void			*take_forks(void *arg);
void			start_eating(int id);
void			philo_sleep(int id);
void			think(int id);
#endif
