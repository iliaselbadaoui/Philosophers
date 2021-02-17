/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 11:10:58 by ielbadao          #+#    #+#             */
/*   Updated: 2021/02/16 16:51:08 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void			start_eating(int id)
{
	philo_state(EATING, id + 1);
	pthread_mutex_lock(&g_eating[id]);
	usleep(g_time_to_eat);
	g_times[id]++;
	g_philos[id] = 1;
	pthread_mutex_unlock(&g_eating[id]);
	pthread_mutex_lock(&g_mutex);
	if (id && g_forks[id] && g_forks[id - 1] && g_times[id] > g_times_compare[id])
	{
		g_forks[id] = 0;
		g_forks[id - 1] = 0;
	}
	else if (g_forks[0] && g_forks[g_philo_num - 1] && g_times[id] > g_times_compare[id])
	{
		g_forks[0] = 0;
		g_forks[g_philo_num - 1] = 0;
	}
	pthread_mutex_unlock(&g_mutex);
}
