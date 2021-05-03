/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 17:08:36 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/03 16:53:36 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void			eat(int id)
{
	if (g_died)
		return ;
	sem_wait(g_eating[id]);
	philo_state(EATING, id + 1);
	usleep(g_time_to_eat);
	sem_post(g_eating[id]);
	g_cycles[id] = 1;
	g_eating_times[id]++;
}
