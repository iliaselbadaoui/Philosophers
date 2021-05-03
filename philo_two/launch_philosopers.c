/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_philosopers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:35:58 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/03 16:33:47 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void			launch_philosophers()
{
	int		i;

	i = 0;
	while (i < g_philo_num)
	{
		g_ids[i] = i;
		pthread_create(&g_philosopers[i], NULL, philosophers_manager, &g_ids[i]);
		i++;
	}
	pthread_create(&g_death_supervisor, NULL, death_supervisor, NULL);
	pthread_join(g_death_supervisor, NULL);
	i = 0;
	while (i < g_philo_num)
	{
		pthread_join(g_philosopers[i], NULL);
		i++;
	}
}
