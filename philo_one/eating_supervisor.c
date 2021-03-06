/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating_supervisor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 18:08:19 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/30 18:09:38 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static int	condition(t_philosoper *philo, int *i)
{
	if (philo->num_of_times_a_philo_ate[*i]
		>= philo->number_of_times_to_eat
		&& philo->number_of_times_to_eat > 0)
	{
		*i = *i + 1;
		return (1);
	}
	return (0);
}

void	*eating_supervisor(void *arg)
{
	int				i;
	t_args			*args;
	t_philosoper	*philo;

	philo = (t_philosoper *)arg;
	args = (t_args *)malloc(sizeof(t_args));
	args->philo = philo;
	while (!philo->done && !philo->died)
	{
		i = 0;
		ft_usleep(philo->time_to_eat);
		while (i < philo->philo_num)
		{
			if (condition(philo, &i))
				philo->done = 1;
			else
			{
				philo->done = 0;
				break ;
			}
		}
	}
	if (philo->done)
		kill_philosophers(args);
	return (NULL);
}
