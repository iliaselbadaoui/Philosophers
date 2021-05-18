/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 03:13:26 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/18 03:10:31 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	kill_philosophers(t_args *args)
{
	int				i;
	t_philosoper	*philo;

	philo = args->philo;
	i = 0;
	while (i < philo->philo_num)
	{
		pthread_detach(philo->threads[i]);
		i++;
	}
}
