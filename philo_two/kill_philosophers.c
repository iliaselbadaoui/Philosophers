/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 19:34:31 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/03 14:25:51 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void			kill_philosophers()
{
	int		i;

	i = 0;
	sem_unlink("OUTPUT_PROTECT");
	sem_unlink("FORKS_SEMA");
	while (i < g_philo_num)
	{
		sem_unlink(g_eating_names[i]);
		pthread_detach(g_philosopers[i]);
		i++;
	}
}
