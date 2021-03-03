/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 19:34:31 by ielbadao          #+#    #+#             */
/*   Updated: 2021/03/03 22:17:27 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void			kill_philosophers()
{
	int		i;

	i = 0;
	while (i < g_philo_num)
	{
		pthread_detach(g_philosopers[i]);
		sem_unlink("OUTPUT_PROTECT");
		sem_unlink("FORKS_PROTECT");
		sem_unlink(g_forks_names[i]);
		sem_unlink(g_eating_names[i]);
		i++;
	}
}
