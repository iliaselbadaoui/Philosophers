/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 12:39:14 by ielbadao          #+#    #+#             */
/*   Updated: 2021/02/12 17:49:22 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static void	init_g(char **argv)
{
	pthread_mutex_init(&g_mutex, NULL);
	pthread_mutex_init(&g_protect, NULL);
	g_philo_num = ft_atoi(argv[1]);
	g_time_to_die = ft_atoi(argv[2]) * 1000;
	g_time_to_eat = ft_atoi(argv[3]) * 1000;
	g_time_to_sleep = ft_atoi(argv[4]) * 1000;
}

int			main(int argc, char **argv)
{
	pthread_t	*thread;
	pthread_t	supervisor;
	int			*ids;
	int			i;
	
	i = 0;
	if (argc >= 5 && argc <= 6)
	{
		init_g(argv);
		if (argc == 6)
			g_number_of_times_of_eat = ft_atoi(argv[5]) * 1000;
		thread = (pthread_t *)malloc(sizeof(pthread_t) * g_philo_num);
		ids = (int *)malloc(sizeof(int) * g_philo_num);
		init_forks();
		while (i < g_philo_num)
		{
			ids[i] = i;
			thread[i] = create_philo(take_forks, &(ids[i]));
			i++;
		}
		pthread_create(&supervisor, NULL, supervisor_thread, (void *) thread);
		pthread_join(supervisor, NULL);
		i = 0;
		while (i < g_philo_num)
			pthread_join(thread[i++], NULL);
	}
	return (0);
}
