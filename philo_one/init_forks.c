/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 13:28:30 by ielbadao          #+#    #+#             */
/*   Updated: 2021/01/07 11:44:21 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		init_forks()
{
	int		i;

	i = 0;
	forks = (int *)malloc(sizeof(int) * g_philo_num);
	philos = (int *)malloc(sizeof(int) * g_philo_num);
	while (i < g_philo_num)
	{
		philos[i] = forks[i] = 0;
		i++;
	}
}
