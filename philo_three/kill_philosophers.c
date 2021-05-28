/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 03:13:26 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/27 14:45:15 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	kill_philosophers(t_args *args)
{
	int				i;
	t_philosoper	*philo;

	philo = args->philo;
	i = 0;
	while (i < philo->philo_num)
	{
		kill(philo->threads[i], SIGQUIT);
		i++;
	}
}
