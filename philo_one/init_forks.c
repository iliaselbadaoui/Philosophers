/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 13:28:30 by ielbadao          #+#    #+#             */
/*   Updated: 2021/01/14 11:57:47 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		init_forks(void)
{
	int		i;

	i = 0;
	g_forks = (int *)malloc(sizeof(int) * g_philo_num);
	g_philos = (int *)malloc(sizeof(int) * g_philo_num);
	while (i < g_philo_num)
	{
		g_philos[i] = 0;
		g_forks[i] = 0;
		i++;
	}
}
