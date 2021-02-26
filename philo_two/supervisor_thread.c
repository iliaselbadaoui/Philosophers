/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor_thread.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 20:06:23 by ielbadao          #+#    #+#             */
/*   Updated: 2021/02/26 11:45:01 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void			kill_philosophers(pthread_t *thread)
{
	int		i;

	i = 0;
	while (i < g_philo_num)
	{
		pthread_detach(thread[i]);
		i++;
	}
}

void			*supervisor_thread(void *ptr)
{
	int				i;
	pthread_t		*thread;

	thread = (pthread_t *)ptr;
	while (!g_died && !g_all_done_eating)
	{
		usleep(g_time_to_die);
		i = 0;
		while (i < g_philo_num)
		{
			sem_wait(g_eating[i]);
			if (g_times[i] == g_times_compare[i])
			{
				g_died = 1;
				philo_state(DIED, i + 1);
				sem_post(g_eating[i]);
				break ;
			}
			g_times_compare[i]++;
			sem_post(g_eating[i]);
			i++;
		}
	}
	kill_philosophers(thread);
	return (NULL);
}
