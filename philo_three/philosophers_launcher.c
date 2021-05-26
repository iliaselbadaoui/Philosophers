/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_launcher.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:23:24 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/18 23:54:36 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static void	supervisors(t_philosoper *philo)
{
	t_args		*args;

	args = (t_args *)malloc(sizeof(t_args));
	args->philo = philo;
	args->id = 0;
	// if ((philo->shinigami = fork()) > 0)
	// 	death_supervisor(args);
	// if ((philo->famine = fork()) > 0)
	// 	eating_supervisor(args);
}

void		philosophers_launcher(t_philosoper *philo)
{
	int			i;
	t_args		*args;
	pthread_t	*philosopher;

	i = 0;
	philosopher = (pthread_t *)malloc(sizeof(pthread_t) * philo->philo_num);
	supervisors(philo);
	while (i < philo->philo_num)
	{
		args = (t_args *)malloc(sizeof(t_args));
		args->philo = philo;
		args->id = i;
		if ((philo->threads[i] = fork()) > 0)
			philosophers((void *) args);
		i++;
	}
}
