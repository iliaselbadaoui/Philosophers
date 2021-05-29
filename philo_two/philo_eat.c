/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 22:12:26 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/29 19:41:41 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void		philo_eat(t_args *args)
{
	int				id;
	t_philosoper	*philo;

	id = args->id;
	philo = args->philo;
	philo_state(EATING, args);
	usleep(philo->time_to_eat);
	philo->times[id] = get_timestamp();
	sem_post(philo->forks);
	sem_post(philo->forks);
}
