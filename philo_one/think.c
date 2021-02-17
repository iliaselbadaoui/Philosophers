/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 12:28:06 by ielbadao          #+#    #+#             */
/*   Updated: 2021/02/17 11:04:06 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void			think(int id)
{
	philo_state(THINKING, id + 1);
	// usleep(g_time_to_sleep);
	g_philos[id] = 0;
}