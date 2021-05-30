/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 21:30:21 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/30 16:13:10 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	*philosophers(void *arg)
{
	t_args	*args;
	int				id;
	t_philosoper	*philo;

	args = (t_args *)arg;
	id = args->id;
	philo = args->philo;

	while (!(args->philo->died) && !(args->philo->done))
	{
		take_forks(args);
		philo_eat(args);
		philo_sleep(args);
		philo_think(args);
	}
	return (NULL);
}
