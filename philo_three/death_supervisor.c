/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_supervisor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 01:55:07 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/18 20:28:21 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

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
			if (!philo->eating[i] && philo->expected_times[i] == philo->times[i] && !philo->done)
			{
				args = (t_args *)malloc(sizeof(t_args));
				args->philo = philo;
				args->id = i;
				philo_state(DIED, args);
				philo->died = 1;
				break ;
			}
			philo->expected_times[i]++;
			i++;
		}
	}
	if (philo->died)
		kill_philosophers(args);
	return (NULL);
}