/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 12:39:14 by ielbadao          #+#    #+#             */
/*   Updated: 2021/01/13 15:49:53 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int			main(int argc, char **argv)
{
	pthread_t	*thread;
	int			*ids;
	int			i;
	
	i = 0;
	if (argc >= 5 && argc <= 6)
	{
		pthread_mutex_init(&g_mutex, NULL);
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
			usleep(100);
			thread[i] = create_philo(take_forks, &(ids[i]));
			i++;
		}
		i = 0;
		while (i < g_philo_num)
			pthread_join(thread[i++], NULL);
	}
	return (0);
}
