/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:07:25 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/05 13:58:58 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H
# define FORK_TAKEN 0
# define EATING 1
# define SLEEPING 2
# define THINKING 3
# define DIED 4
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <semaphore.h>
# include <unistd.h>
# include <sys/time.h>

typedef char	*t_string;

// sem_t			*g_mutex;
sem_t			*g_protect_output;
sem_t			**g_eating;
sem_t			*g_protect_forks;
sem_t			*g_forks;
pthread_t		*g_thread;
t_string		*g_names;
int				*g_philos;
int				*g_times;
int				*g_times_compare;
int				*g_ids;
int				g_all_done_eating;
int				g_philo_num;
int				g_time_to_eat;
int				g_time_to_sleep;
int				g_time_to_die;
int				g_number_of_times_of_eat;
int				g_died;

pthread_t		create_philo(void *(func(void *arg)), int *id);
void			init_forks(void);
void			*take_forks(void *arg);
void			start_eating(int id);
void			philo_sleep(int id);
void			*supervisor_thread(void *ptr);
void			ft_putnbr(long n);
int				ft_atoi(char *number);
void			println(char *str);
void			philo_state(int state, int philo_id);
void			kill_philosophers(pthread_t		*thread);
void			*eating_times_supervisor(void *arg);
void			think(int id);
void			frees(void);
t_string		sema_name_gen();
#endif