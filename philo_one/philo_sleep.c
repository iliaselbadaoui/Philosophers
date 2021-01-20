/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 12:53:22 by ielbadao          #+#    #+#             */
/*   Updated: 2021/01/20 22:25:45 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void			philo_sleep(int id)
{
	struct timeval	tval;

	gettimeofday(&tval, NULL);
	printf("%ld %d is sleeping\n", tval.tv_sec, id + 1);
	usleep(g_time_to_sleep);
}