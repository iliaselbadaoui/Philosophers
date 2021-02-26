/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 10:38:17 by ielbadao          #+#    #+#             */
/*   Updated: 2021/02/25 13:06:15 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static void		help(int id, int *flag)
{
	g_forks[0] = 1;
	g_forks[g_philo_num - 1] = 1;
	philo_state(FORK_TAKEN, id + 1)	;
	*flag = 1;
}

static void		help2(int id, int *flag)
{
	g_forks[id] = 1;
	g_forks[id - 1] = 1;
	philo_state(FORK_TAKEN, id + 1);
	*flag = 1;
}

static void		help3(int id)
{
	start_eating(id);
	philo_sleep(id);
	think(id);
}

void			*take_forks(void *arg)
{
	int				id;
	int				flag;

	id = *((int *)arg);
	while (!g_died)
	{
		flag = 0;
		while (!flag && !g_died)
		{
			sem_post(g_semaphore);
			if (id && !g_forks[id - 1] && !g_forks[id] && g_times[id] ==
			g_times_compare[id])
				help2(id, &flag);
			else if (!id && !g_forks[g_philo_num - 1] && !g_forks[0] &&
			g_times[id] == g_times_compare[id])
				help(id, &flag);
			sem_post(g_semaphore);
		}
		if (!g_died)
			help3(id);
	}
	return (NULL);
}
