/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 22:12:26 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/18 02:18:44 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		philo_eat(t_args *args)
{
	int				id;
	t_philosoper	*philo;

	id = args->id;
	philo = args->philo;
	if (philo->died)
		return ;
	philo_state(EATING, args);
	philo->eating[id] = 1;
	usleep(philo->time_to_eat);
	philo->times[id]++;
	if (id && philo->forks[id] && philo->forks[id - 1])
	{
		philo->forks[id] = 0;
		philo->forks[id - 1] = 0;
	}
	else if (!id && philo->forks[id] && philo->forks[philo->philo_num - 1])
	{
		philo->forks[id] = 0;
		philo->forks[philo->philo_num - 1] = 0;
	}
	philo->eating[id] = 0;
}
