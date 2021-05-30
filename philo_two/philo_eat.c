/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 22:12:26 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/30 14:19:10 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void		philo_eat(t_args *args)
{
	int				id;
	t_philosoper	*philo;

	id = args->id;
	philo = args->philo;
	sem_wait(philo->protect_eating[id]);
	philo_state(EATING, args);
	philo->times[id] = get_timestamp();
	philo->num_of_times_a_philo_ate[id]++;
	ft_usleep(philo->time_to_eat);
	sem_post(philo->forks);
	sem_post(philo->forks);
	sem_post(philo->protect_eating[id]);
}
