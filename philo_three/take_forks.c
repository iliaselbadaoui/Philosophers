/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 10:38:17 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/06 10:41:08 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

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
			sem_wait(g_protect_forks);
			sem_wait(g_forks);
			sem_wait(g_forks);
			philo_state(FORK_TAKEN, id + 1);
			flag = 1;
			sem_post(g_protect_forks);
		}
		if (!g_died)
			help3(id);
	}
	return (NULL);
}
