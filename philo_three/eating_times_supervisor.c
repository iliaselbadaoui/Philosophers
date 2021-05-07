/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating_times_supervisor.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:30:07 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/05 12:18:20 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void			*eating_times_supervisor(void *arg)
{
	int		i;

	arg = NULL;
	while (!g_all_done_eating && !g_died)
	{
		i = 0;
		usleep(g_time_to_eat);
		while (i < g_philo_num)
		{
			if (g_times[i] >= g_number_of_times_of_eat &&
			g_number_of_times_of_eat > 0)
				g_all_done_eating = 1;
			else
			{
				g_all_done_eating = 0;
				break ;
			}
			i++;
		}
	}
	kill_philosophers(g_thread);
	return (NULL);
}
