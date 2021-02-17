/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 10:38:17 by ielbadao          #+#    #+#             */
/*   Updated: 2021/02/16 17:05:54 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static void		help(int id, int *flag)
{

	g_forks[0] = 1;
	g_forks[g_philo_num - 1] = 1;
	philo_state(FORK_TAKEN, id + 1)	;
	*flag = 1;
}

void			help2(int id, int *flag)
{
	g_forks[id] = 1;
	g_forks[id - 1] = 1;
	philo_state(FORK_TAKEN, id + 1);
	*flag = 1;
}

void			*take_forks(void *arg)
{
	int				id;
	int				flag;

	id  = *((int *)arg);
	while (!g_died)
	{
		flag = 0;
		while (!flag && !g_died)
		{
			pthread_mutex_lock(&g_mutex);
			if (id && !g_forks[id - 1] && !g_forks[id] && g_times[id] == g_times_compare[id])
				help2(id, &flag);
			else if(!id && !g_forks[g_philo_num - 1] && !g_forks[0] && g_times[id] == g_times_compare[id])
				help(id, &flag);
			pthread_mutex_unlock(&g_mutex);
		}
		if (!g_died)
		{
			start_eating(id);
			philo_sleep(id);
			think(id);
		}
	}
	return (NULL);
}
