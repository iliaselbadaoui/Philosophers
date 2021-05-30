/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_supervisor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 01:55:07 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/30 09:52:42 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	*death_supervisor(void *arg)
{
	int				i;
	t_philosoper	*philo;
	t_args			*args;
	int				diff;

	philo = (t_philosoper *)arg;
	while (!philo->died && !philo->done)
	{
		usleep(philo->time_to_die);
		i = 0;
		while (i < philo->philo_num)
		{
			sem_wait(philo->protect_eating[i]);
			diff = get_timestamp() - philo->times[i];
			if (diff > philo->time_to_die / 1000)
			{
				args = (t_args *)malloc(sizeof(t_args));
				args->philo = philo;
				args->id = i;
				philo_state(DIED, args);
				philo->died = 1;
				break ;
			}
			sem_post(philo->protect_eating[i]);
			i++;
		}
	}
	if (philo->died)
		kill_philosophers(args);
	return (NULL);
}