/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 13:28:30 by ielbadao          #+#    #+#             */
/*   Updated: 2021/02/13 11:27:27 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		init_forks(void)
{
	int		i;

	i = 0;
	g_forks = (int *)malloc(sizeof(int) * g_philo_num);
	g_philos = (int *)malloc(sizeof(int) * g_philo_num);
	g_times = (int *)malloc(sizeof(int) * g_philo_num);
	g_times_compare = (int *)malloc(sizeof(int) * g_philo_num);
	while (i < g_philo_num)
	{
		g_philos[i] = 0;
		g_forks[i] = 0;
		g_times[i] = 0;
		g_times_compare[i] = 0;
		i++;
	}
}
