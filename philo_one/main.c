/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 12:39:14 by ielbadao          #+#    #+#             */
/*   Updated: 2021/01/13 09:35:27 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		*take_forks(void *arg)
{
	int				id;
	int				i;
	struct timeval	tval;

	id  = *((int *) arg);
	i = 0;
	pthread_mutex_lock(&mutex);
	while (i++ < g_philo_num)
	{
		if (id && !forks[id - 1] && !forks[id] && !philos[id])
		{
			philos[id] = 1;
			forks[id] = 1;
			forks[id - 1] = 1;
			gettimeofday(&tval, NULL);
			printf("%ld %d has taken a fork\n", tval.tv_sec, id+1);
			forks[id] = 0;
			forks[id - 1] = 0;
			break ;
		}
		else if(!forks[g_philo_num - 1] && !forks[0] && !philos[0])
		{
			philos[0] = 1;
			forks[0] = 1;
			forks[g_philo_num - 1] = 1;
			gettimeofday(&tval, NULL);
			printf("%ld %d has taken a fork\n", tval.tv_sec, id+1);
			forks[0] = 0;
			forks[g_philo_num - 1] = 0;
			break ;
		}
	}
	pthread_mutex_unlock(&mutex);
	return (NULL);
}

int			main(int argc, char **argv)
{
	pthread_t	*thread;
	int			*ids;
	int			i;
	
	i = 0;
	if (argc >= 5 && argc <= 6)
	{
		pthread_mutex_init(&mutex, NULL);
		g_philo_num = atoi(argv[1]);
		g_time_to_die = atoi(argv[2]);
		g_time_to_eat = atoi(argv[3]);
		g_time_to_sleep = atoi(argv[4]);
		if (argc == 6)
			g_number_of_times_of_eat = atoi(argv[5]);
		thread = (pthread_t *)malloc(sizeof(pthread_t) * g_philo_num);
		ids = (int *)malloc(sizeof(int) * g_philo_num);
		init_forks();
		while (i < g_philo_num)
		{
			ids[i] = i;
			thread[i] = create_philo(take_forks, &(ids[i]));
			i++;
		}
		i = 0;
		while (i < g_philo_num)
			pthread_join(thread[i++], NULL);
	}
	return (0);
}
