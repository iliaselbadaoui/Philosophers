/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:07:25 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/30 18:15:20 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H
# define FORK_TAKEN 0
# define EATING 1
# define SLEEPING 2
# define THINKING 3
# define DIED 4
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <semaphore.h>
# include <sys/time.h>

typedef char	*t_string;
typedef struct s_philosopher
{
	sem_t			*protect_forks;
	sem_t			**protect_eating;
	sem_t			*protect_output;
	sem_t			*forks;
	t_string		*sem_names;
	pthread_t		*threads;
	pthread_t		shinigami;
	pthread_t		famine;
	long			*times;
	int				*num_of_times_a_philo_ate;
	int				philo_num;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				number_of_times_to_eat;
	int				died;
	int				done;
}	t_philosoper;

typedef struct s_args
{
	int				id;
	t_philosoper	*philo;
}	t_args;
typedef enum e_bool
{
	false,
	true
}	t_bool;

t_bool			is_number(t_string nbr);
t_string		sema_name_gen(void);
int				ft_atoi(t_string number);
void			println(t_string str, int fd);
void			ft_putnbr(long n);
void			ft_usleep(int span);
long			get_timestamp(void);
void			philosophers_launcher(t_philosoper *philo);
void			*philosophers(void *arg);
void			*death_supervisor(void *arg);
void			*eating_supervisor(void *arg);
void			kill_philosophers(t_args *args);
void			philo_state(int state, t_args *args);
void			*take_forks(t_args *args);
void			philo_eat(t_args *args);
void			philo_sleep(t_args *args);
void			philo_think(t_args *args);
#endif
