/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_supervisor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 19:19:48 by ielbadao          #+#    #+#             */
/*   Updated: 2021/03/05 10:24:58 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void			*death_supervisor()
{
	int				i;

	while (!g_died && !g_done_eating)
	{
		usleep(g_time_to_die);
		i = 0;
		while (i < g_philo_num)
		{
			sem_wait(g_eating[i]);
			if (g_eating_times[i] == g_eating_times_count[i])
			{
				philo_state(DIED, i + 1);
				g_died = 1;
				sem_post(g_eating[i]);
				break ;
			}
			sem_post(g_eating[i]);
			g_eating_times_count[i]++;
			i++;
		}
	}
	kill_philosophers();
	return (NULL);
}
