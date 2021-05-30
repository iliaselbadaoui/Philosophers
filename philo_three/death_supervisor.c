/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_supervisor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 01:55:07 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/30 17:27:25 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	*death_supervisor(void *arg)
{
	int				i;
	t_philosoper	*philo;
	t_args			*args;
	int				diff;

	args = (t_args *)arg;
	philo = args->philo;
	i = args->id;
	while (1)
	{
		sem_wait(philo->protect_eating[i]);
		diff = get_timestamp() - philo->times[i];
		if (diff > philo->time_to_die / 1000)
		{
			philo_state(DIED, args);
			break ;
		}
		sem_post(philo->protect_eating[i]);
	}
	sem_post(philo->wait_end);
	return (NULL);
}