/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 12:00:47 by ielbadao          #+#    #+#             */
/*   Updated: 2021/03/04 19:21:08 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static int		help_take_forks(int id)
{
	if (id == g_philo_num - 1)
	{
		sem_wait(g_forks[0]);
		sem_wait(g_forks[g_philo_num - 1]);
	}
	else
	{
		sem_wait(g_forks[id]);
		sem_wait(g_forks[id + 1]);
	}
	return (1);
}

void			take_forks(int id)
{
	int		done;

	done = 0;
	while (!done)
	{
		sem_wait(g_protect_forks);
		if (!g_cycles[id])
			if (!help_take_forks(id))
				continue ;
		philo_state(FORK_TAKEN, id + 1);
		done = 1;
		sem_post(g_protect_forks);
	}
}
