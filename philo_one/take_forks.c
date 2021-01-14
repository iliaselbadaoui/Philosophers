/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 10:38:17 by ielbadao          #+#    #+#             */
/*   Updated: 2021/01/14 19:04:31 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static void		help(int id)
{
	struct timeval	tval;

	g_philos[0] = 1;
	g_forks[0] = 1;
	g_forks[g_philo_num - 1] = 1;
	gettimeofday(&tval, NULL);
	printf("%ld %d has taken a fork\n", tval.tv_sec, id + 1);
}

void			*take_forks(void *arg)
{
	int				id;
	int				flag;
	struct timeval	tval;

	id  = *((int *)arg);
	flag = 0;
	while (1)
	{
		pthread_mutex_lock(&g_mutex);
		if (id && !g_forks[id - 1] && !g_forks[id] && !g_philos[id])
		{
			g_philos[id] = 1;
			g_forks[id] = 1;
			g_forks[id - 1] = 1;
			gettimeofday(&tval, NULL);
			printf("%ld %d has taken a fork\n", tval.tv_sec, id + 1);
			break ;
		}
		else if(!g_forks[g_philo_num - 1] && !g_forks[0] && !g_philos[0])
		{
			help(id);
			break ;
		}
	}
	start_eating(id);
	philo_sleep(id);
	think(id);
	return (NULL);
}
