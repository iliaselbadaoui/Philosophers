/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor_thread.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 20:06:23 by ielbadao          #+#    #+#             */
/*   Updated: 2021/02/13 11:49:00 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		kill_philosophers(pthread_t		*thread)
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
	struct timeval	tval;

	thread = (pthread_t *)ptr;
	while (!g_died)
	{
		usleep(g_time_to_die);
		i = 0;
		while (i < g_philo_num)
		{
			if(!g_times[i])
			{
				
				g_died = 1;
				gettimeofday(&tval, NULL);
				philo_state(DIED, i + 1);
				break ;
			}
			g_times_compare[i]++;
			i++;
		}
	}
	kill_philosophers(thread);
	return (NULL);
}
