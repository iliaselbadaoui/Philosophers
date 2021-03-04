/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 17:08:36 by ielbadao          #+#    #+#             */
/*   Updated: 2021/03/04 17:37:47 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void			eat(int id)
{
	sem_wait(g_eating[id]);
	philo_state(EATING, id + 1);
	usleep(g_time_to_eat);
	if (id == g_philo_num - 1)
	{
		sem_post(g_forks[0]);
		sem_post(g_forks[g_philo_num - 1]);
	}
	else
	{
		sem_post(g_forks[id]);
		sem_post(g_forks[id + 1]);
	}
	g_cycles[id] = 1;
	g_eating_times[id]++;
	sem_post(g_eating[id]);
}
