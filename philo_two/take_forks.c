/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 12:00:47 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/03 10:55:02 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void			take_forks(int id)
{
	int		done;

	done = 0;
	while (!done)
	{
		if (!g_cycles[id])
			if (!sem_wait(g_forks))
			{
				if (!sem_wait(g_forks))
				{
					philo_state(FORK_TAKEN, id + 1);
					done = 1;
				}
				else
					sem_post(g_forks);
			}
	}
}
