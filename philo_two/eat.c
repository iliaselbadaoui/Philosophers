/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 17:08:36 by ielbadao          #+#    #+#             */
/*   Updated: 2021/03/03 18:03:12 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void			eat(int id)
{
	philo_state(EATING, id + 1);
	sem_wait(g_eating[id]);
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
	sem_post(g_eating[id]);
}
