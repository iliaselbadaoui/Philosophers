/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:15:22 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/30 15:46:57 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	*take_forks(t_args *args)
{
	int				id;
	t_philosoper	*philo;

	id = args->id;
	philo = args->philo;
	if (id % 2 != 0)
	{
		pthread_mutex_lock(&philo->forks[(id + 1) % philo->philo_num]);
		pthread_mutex_lock(&philo->forks[id]);
		philo_state(FORK_TAKEN, args);
		philo_state(FORK_TAKEN, args);
	}
	else
	{
		pthread_mutex_lock(&philo->forks[id]);
		pthread_mutex_lock(&philo->forks[(id + 1) % philo->philo_num]);
		philo_state(FORK_TAKEN, args);
		philo_state(FORK_TAKEN, args);
	}
	return (NULL);
}
