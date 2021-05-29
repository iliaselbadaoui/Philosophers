/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:15:22 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/29 11:32:29 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	*take_forks(t_args *args)
{
	int				id;
	int				done;
	t_philosoper	*philo;

	id = args->id;
	philo = args->philo;
	done = 0;
	while (!done && !philo->died)
	{
		// pthread_mutex_lock(&(philo->protect_forks));
		if (id)
		{
			pthread_mutex_lock(&philo->forks[id]);
			pthread_mutex_lock(&philo->forks[id - 1]);
			philo_state(FORK_TAKEN, args);
			philo_state(FORK_TAKEN, args);
			done = 1;
		}
		else if (!id)
		{
			pthread_mutex_lock(&philo->forks[id]);
			pthread_mutex_lock(&philo->forks[philo->philo_num - 1]);
			philo_state(FORK_TAKEN, args);
			philo_state(FORK_TAKEN, args);
			done = 1;
		}
		// pthread_mutex_unlock(&(philo->protect_forks));
	}	
	return (NULL);
}
