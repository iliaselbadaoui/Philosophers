/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_launcher.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:23:24 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/26 21:15:39 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static void	supervisors(t_philosoper *philo)
{
	t_args		*args;

	args = (t_args *)malloc(sizeof(t_args));
	args->philo = philo;
	args->id = 0;
	philo->shinigami = fork();
	philo->famine = fork();
	if (philo->shinigami == 0)
		death_supervisor(args);
	if (philo->famine == 0)		eating_supervisor(args);
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
		philo->threads[i] = fork();
		if (philo->threads[i] == 0)
			philosophers((void *) args);
		i++;
	}
}
