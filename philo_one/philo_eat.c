/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 22:12:26 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/29 11:31:52 by ielbadao         ###   ########.fr       */
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
	pthread_mutex_lock(&philo->protect_eating[id]);
	philo_state(EATING, args);
	philo->times[id] = get_timestamp();
	usleep(philo->time_to_eat);
	pthread_mutex_unlock(&philo->protect_eating[id]);
	if (id)
	{
		pthread_mutex_unlock(&philo->forks[id]);
		pthread_mutex_unlock(&philo->forks[id - 1]);
	}
	else if (!id)
	{
		pthread_mutex_unlock(&philo->forks[id]);
		pthread_mutex_unlock(&philo->forks[philo->philo_num - 1]);
	}
}
