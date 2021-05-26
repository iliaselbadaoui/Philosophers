/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:15:22 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/18 23:43:28 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

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
		sem_wait(philo->protect_forks);
		sem_wait(philo->forks);
		sem_wait(philo->forks);
		philo_state(FORK_TAKEN, args);
		philo_state(FORK_TAKEN, args);
		done = 1;
		sem_post(philo->protect_forks);
	}	
	return (NULL);
}
