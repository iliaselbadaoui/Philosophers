/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 11:10:58 by ielbadao          #+#    #+#             */
/*   Updated: 2021/02/26 11:44:57 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void			start_eating(int id)
{
	philo_state(EATING, id + 1);
	sem_wait(g_eating[id]);
	usleep(g_time_to_eat);
	g_times[id]++;
	g_philos[id] = 1;
	sem_post(g_eating[id]);
	sem_wait(g_semaphore);
	if (id && g_forks[id] && g_forks[id - 1] && g_times[id] >
	g_times_compare[id])
	{
		g_forks[id] = 0;
		g_forks[id - 1] = 0;
	}
	else if (g_forks[0] && g_forks[g_philo_num - 1] && g_times[id] >
	g_times_compare[id])
	{
		g_forks[0] = 0;
		g_forks[g_philo_num - 1] = 0;
	}
	sem_post(g_semaphore);
}
