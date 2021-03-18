/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 13:32:12 by ielbadao          #+#    #+#             */
/*   Updated: 2021/03/05 11:55:12 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TOW_H
# define PHILO_TOW_H
# define FORK_TAKEN 0
# define EATING 1
# define SLEEPING 2
# define THINKING 3
# define DIED 4
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>

typedef char	*t_string;

sem_t			*g_output;
sem_t			*g_forks;
sem_t			**g_eating;
t_string		*g_eating_names;
pthread_t		*g_philosopers;
pthread_t		g_death_supervisor;
pthread_t		g_eating_supervisor;
int				g_philo_num;
int				g_time_to_eat;
int				g_time_to_sleep;
int				g_time_to_die;
int				g_number_of_times_of_eat;
int				g_died;
int				*g_eating_times;
int				*g_eating_times_count;
int				*g_ids;
int				*g_cycles;
int				g_done_eating;

void			ft_putnbr(long n);
int				ft_atoi(t_string number);
void			println(t_string str);
void			*philosophers_manager(void *id_arg);
void			philo_state(int state, int philo_id);
void			launch_philosophers();
void			take_forks(int id);
t_string		sema_name_gen();
void			think(int id);
void			eat(int id);
void			philo_sleep(int id);
void			*death_supervisor();
void			kill_philosophers();
#endif
