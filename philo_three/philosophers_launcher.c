/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_launcher.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:23:24 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/28 14:24:10 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static void	supervisors(t_philosoper *philo)
{
	philo->shinigami = fork();
	if (philo->shinigami == 0)
		death_supervisor(philo);
	else if (philo->shinigami < 0)
			return ;
	philo->famine = fork();
	if (philo->famine == 0)
		eating_supervisor(philo);
	else if (philo->famine< 0)
			return ;
}

void		philosophers_launcher(t_philosoper *philo)
{
	int			i;
	t_args		*args;
	// pthread_t	*philosopher;

	i = 0;
	// philosopher = (pthread_t *)malloc(sizeof(pthread_t) * philo->philo_num);
	while (i < philo->philo_num)
	{
		args = (t_args *)malloc(sizeof(t_args));
		args->philo = philo;
		args->id = i;
		philo->threads[i] = fork();
		if (philo->threads[i] == 0)
			philosophers((void *) args);
		else if (philo->threads[i] < 0)
			return ;
		i++;
	}
	supervisors(philo);
	sleep(5);
	kill(philo->famine, SIGINT);
	kill(philo->shinigami, SIGINT);
	i = 0;
	while (i < philo->philo_num)
	{
		kill(philo->threads[i], SIGINT);
		i++;
	}
	waitpid(-1, NULL, 0);
}
