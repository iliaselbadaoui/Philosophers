/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:10:40 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/03 16:40:46 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void			philo_sleep(int id)
{
	if (g_died)
		return ;
	philo_state(SLEEPING, id + 1);
	sem_post(g_forks);
	sem_post(g_forks);
	usleep(g_time_to_sleep);
}
