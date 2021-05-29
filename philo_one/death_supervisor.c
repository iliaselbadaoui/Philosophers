/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_supervisor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 01:55:07 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/29 10:25:34 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	*death_supervisor(void *arg)
{
	int				i;
	t_philosoper	*philo;
	t_args			*args;

	philo = (t_philosoper *)arg;
	while (!philo->died && !philo->done)
	{
		usleep(philo->time_to_die);
		i = 0;
		while (i < philo->philo_num)
		{
			pthread_mutex_lock(&philo->protect_eating[i]);
			if (get_timestamp() - philo->times[i] > philo->time_to_die && !philo->done)
			{
				args = (t_args *)malloc(sizeof(t_args));
				args->philo = philo;
				args->id = i;
				philo_state(DIED, args);
				philo->died = 1;
				break ;
			}
			pthread_mutex_unlock(&philo->protect_eating[i]);
			i++;
		}
	}
	if (philo->died)
		kill_philosophers(args);
	return (NULL);
}