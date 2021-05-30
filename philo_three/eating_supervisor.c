/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating_supervisor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 18:08:19 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/30 16:13:10 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

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
			if (philo->num_of_times_a_philo_ate[i] >= philo->number_of_times_to_eat
				&& philo->number_of_times_to_eat > 0)
				philo->done = 1;
			else
			{
				philo->done = 0;
				break ;
			}
			i++;
		}
	}
	if (philo->done)
		kill_philosophers(args);
	return (NULL);
}
