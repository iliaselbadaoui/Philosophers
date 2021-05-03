/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 13:32:23 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/03 16:33:44 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static int		error_handler(int argc, t_string *argv)
{
	if (argc < 5 || argc > 6)
	{
		println("There must be 5 or 6 Args\n");
		return (0);
	}
	g_philo_num = ft_atoi(argv[1]);
	g_time_to_die = ft_atoi(argv[2]) * 1000;
	g_time_to_eat = ft_atoi(argv[3]) * 1000;
	g_time_to_sleep = ft_atoi(argv[4]) * 1000;
	g_number_of_times_of_eat = -1;
	if (argc == 6)
		g_number_of_times_of_eat = ft_atoi(argv[5]);
	if (g_philo_num <= 0 || g_time_to_die <= 0 || g_time_to_eat <= 0 ||
	g_time_to_sleep <= 0 || (argc == 6 && g_number_of_times_of_eat <= 0))
	{
		println("All args must be positive\n");
		return (0);
	}
	g_philosopers = (pthread_t *)malloc(sizeof(pthread_t) * g_philo_num);
	g_eating_names = (t_string *)malloc(sizeof(t_string) * g_philo_num);
	g_eating = (sem_t **)malloc(sizeof(sem_t * ) * g_philo_num);
	return (1);
}

static void		initializer()
{
	int		i;

	i = 0;
	g_cycles = (int *)malloc(sizeof(int) * g_philo_num);
	g_eating_times = (int *)malloc(sizeof(int) * g_philo_num);
	g_eating_times_count = (int *)malloc(sizeof(int) * g_philo_num);
	g_ids = (int *)malloc(sizeof(int) * g_philo_num);
	sem_unlink("OUTPUT_PROTECT");
	g_output = sem_open("OUTPUT_PROTECT", O_CREAT, S_IRWXU, 1);
	sem_unlink("FORKS_PROTECT");
	g_protect = sem_open("FORKS_PROTECT", O_CREAT, S_IRWXU, 1);
	sem_unlink("FORKS_SEMA");
	g_forks = sem_open("FORKS_SEMA", O_CREAT, S_IRWXU, g_philo_num);
	while (i < g_philo_num)
	{	
		g_eating_names[i] = sema_name_gen();
		sem_unlink(g_eating_names[i]);
		g_eating[i] = sem_open(g_eating_names[i], O_CREAT, S_IRWXU, 1);
		g_cycles[i] = 0;
		g_eating_times[i] = 0;
		g_eating_times_count[i] = 0;
		i++;
	}
}

int				main(int argc, t_string *argv)
{
	if (!error_handler(argc, argv))
		return (1);
	initializer();
	launch_philosophers();
	return (0);
}
