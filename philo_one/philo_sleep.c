/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:29:47 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/29 17:46:45 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	philo_sleep(t_args *args)
{
	int				id;
	t_philosoper	*philo;

	id = args->id;
	philo = args->philo;
	philo_state(SLEEPING, args);
	ft_usleep(philo->time_to_sleep);
}
