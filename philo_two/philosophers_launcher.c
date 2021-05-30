/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_launcher.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:23:24 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/30 09:53:20 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static void	supervisors(t_philosoper *philo)
{
	pthread_create(&(philo->shinigami), NULL, death_supervisor, (void *)philo);
	pthread_create(&(philo->famine), NULL, eating_supervisor, (void *)philo);
}

void		philosophers_launcher(t_philosoper *philo)
{
	int			i;
	t_args		*args;

	i = 0;
	supervisors(philo);
	while (i < philo->philo_num)
	{
		args = (t_args *)malloc(sizeof(t_args));
		args->philo = philo;
		args->id = i;
		pthread_create(&(philo->threads[i]), NULL, philosophers, (void *)args);
		i++;
	}
	pthread_join(philo->shinigami, NULL);
	pthread_join(philo->famine, NULL);
	i = 0;
	while (i < philo->philo_num)
	{
		pthread_join(philo->threads[i], NULL);
		i++;
	}
}
