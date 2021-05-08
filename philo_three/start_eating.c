/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 11:10:58 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/08 10:56:25 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void			start_eating(int id)
{
	sem_wait(g_eating[id]);
	philo_state(EATING, id + 1);
	g_philos[id] = 1;
	usleep(g_time_to_eat);
	g_times[id]++;
	sem_post(g_eating[id]);
	sem_post(g_forks);
	sem_post(g_forks);
	g_philos[id] = 0;
}