/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:33:35 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/30 17:22:36 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef philo_three_H
# define philo_three_H
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
	sem_t			*wait_end;
	sem_t			**wait_eat;
	t_string		*sem_names;
	t_string		*sem_wait_names;
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
}	t_philosoper;

typedef struct		s_args
{
	int				id;
	t_philosoper	*philo;
}	t_args;
typedef enum	e_bool
{
	false,
	true
}	t_bool;

t_bool			is_number(t_string nbr);
t_string		sema_name_gen();
int				ft_atoi(t_string number);
void			println(t_string str, int fd);
void			ft_putnbr(long n);
void 			ft_usleep(int span);
long			get_timestamp();
void			philosophers_launcher(t_philosoper *philo, pid_t *pids);
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
