/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_supervisor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 01:55:07 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/28 17:20:35 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	*death_supervisor(void *arg)
{
	int				i = 0;
	t_philosoper	*philo;
	t_args			*args;

	philo = (t_philosoper *)arg;
	// printf("died(%d) done(%d) philos(%d)\n", philo->died, philo->done, philo->philo_num);
	while (!philo->died && !philo->done)
	{
		usleep(philo->time_to_die);
		i = 0;
		while (i < philo->philo_num)
		{
			printf("EXPECTED(%d) EATEN (%d)\n", philo->expected_times[i], philo->times[i]);
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