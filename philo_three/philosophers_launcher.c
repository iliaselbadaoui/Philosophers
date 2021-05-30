/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_launcher.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:23:24 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/30 18:39:34 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static void	supervisors(t_args *args)
{
	t_philosoper	*philo;

	philo = args->philo;
	pthread_create(&(philo->shinigami), NULL, death_supervisor, (void *)args);
}

static void	go_ahead(t_args *args)
{
	t_philosoper	*philo;
	int				id;
	int				i;

	philo = args->philo;
	id = args->id;
	supervisors(args);
	pthread_create(&(philo->threads[id]), NULL, philosophers, (void *)args);
	pthread_join(philo->shinigami, NULL);
	pthread_join(philo->famine, NULL);
	i = 0;
	while (i < philo->philo_num)
	{
		pthread_join(philo->threads[i], NULL);
		i++;
	}
}

void	free_args(t_args **args)
{
	free(*args);
	*args = NULL;
}

void	philosophers_launcher(t_philosoper *philo, pid_t *pids)
{
	int			i;
	t_args		*args;

	i = 0;
	args = (t_args *)malloc(sizeof(t_args));
	args->philo = philo;
	if (philo->number_of_times_to_eat != -1)
		pthread_create(&(philo->famine), NULL, eating_supervisor, (void *)args);
	else
		free_args(&args);
	while (i < philo->philo_num)
	{
		args = (t_args *)malloc(sizeof(t_args));
		args->philo = philo;
		args->id = i;
		pids[i] = fork();
		if (pids[i] == 0)
			go_ahead(args);
		else
			free_args(&args);
		i++;
	}
}
