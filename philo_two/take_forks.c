/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:15:22 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/30 09:51:26 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	*take_forks(t_args *args)
{
	int				id;
	t_philosoper	*philo;

	id = args->id;
	philo = args->philo;
	sem_wait(philo->protect_forks);
	sem_wait(philo->forks);
	sem_wait(philo->forks);
	philo_state(FORK_TAKEN, args);
	philo_state(FORK_TAKEN, args);
	sem_post(philo->protect_forks);
	return (NULL);
}
