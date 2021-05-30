/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_supervisor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 01:55:07 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/30 18:05:53 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static void	shinegami_helper(t_args **args, t_philosoper *philo, int id)
{
	(*args) = (t_args *)malloc(sizeof(t_args));
	(*args)->philo = philo;
	(*args)->id = id;
	philo_state(DIED, *args);
	philo->died = 1;
}

void	*death_supervisor(void *arg)
{
	int				i;
	t_philosoper	*philo;
	t_args			*args;
	int				diff;

	philo = (t_philosoper *)arg;
	while (!philo->died && !philo->done)
	{
		i = 0;
		while (i < philo->philo_num)
		{
			sem_wait(philo->protect_eating[i]);
			diff = get_timestamp() - philo->times[i];
			if (diff > philo->time_to_die / 1000 && !philo->done)
			{
				shinegami_helper(&args, philo, i);
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
