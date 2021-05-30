/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating_supervisor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 18:08:19 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/30 17:28:28 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	*eating_supervisor(void *arg)
{
	int				i;
	t_args			*args;
	t_philosoper	*philo;
	int				total;

	args = (t_args *)arg;
	philo = args->philo;
	i = args->id;
	total = 0;
	while (total < philo->number_of_times_to_eat)
	{
		i = 0;
		while (i < philo->philo_num)
		{
			sem_wait(philo->wait_eat[i++]);
		}
		total++;
	}
	sem_post(philo->wait_end);
	return (NULL);
}
