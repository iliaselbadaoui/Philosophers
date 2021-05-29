/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 18:09:27 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/29 18:37:11 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static t_bool check_args(int argc, t_string *argv)
{
	if (argc > 6 || argc < 5)
	{
		println("The programe must have 4 or 5 args\n", 2);
		return (false);
	}
	argv++;
	while (*argv)
	{
		if (!is_number(*argv))
		{
			println("All args must be numbers\n", 2);
			return (false);
		}
		else if (ft_atoi(*argv) < 0)
		{
			println("All args must be positive numbers\n", 2);
			return (false);
		}
		argv++;
	}
	return (true);
}

static void	create_philosopher(int argc, t_string *argv, t_philosoper **philo)
{
	argv++;
	(*philo) = (t_philosoper *)malloc(sizeof(t_philosoper));
	(*philo)->philo_num = ft_atoi(argv[0]);
	(*philo)->time_to_die = ft_atoi(argv[1]) * 1000;
	(*philo)->time_to_eat = ft_atoi(argv[2]) * 1000;
	(*philo)->time_to_sleep = ft_atoi(argv[3]) * 1000;
	if (argc == 6)
		(*philo)->number_of_times_to_eat = ft_atoi(argv[4]);
	else
		(*philo)->number_of_times_to_eat = -1;
	(*philo)->threads = (pthread_t *)malloc(sizeof(pthread_t) * (*philo)->philo_num);
	(*philo)->times = (int *)malloc(sizeof(int) * (*philo)->philo_num);
}

static void	init_values(t_philosoper *philo)
{
	int			i;

	i = 0;
	sem_unlink("FORKS");
	sem_unlink("PROTECT_FORKS");
	sem_unlink("PROTECT_OUTPUT");
	philo->forks = sem_open("FORKS", O_CREAT, 0777, philo->philo_num);
	philo->protect_forks = sem_open("PROTECT_FORKS", O_CREAT, 0777, 1);
	philo->protect_output = sem_open("PROTECT_OUTPUT", O_CREAT, 0777, 1);
	philo->died = 0;
	philo->done = 0;
	while (i < philo->philo_num)
	{
		philo->times[i] = 0;
		i++;
	}
}

int	main(int argc, t_string *argv)
{
	t_philosoper	*philo;

	philo = NULL;
	if (!check_args(argc, argv))
		return (1);
	create_philosopher(argc, argv, &philo);
	init_values(philo);
	philosophers_launcher(philo);
	return (0);
}
