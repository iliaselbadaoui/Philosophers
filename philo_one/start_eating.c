/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 11:10:58 by ielbadao          #+#    #+#             */
/*   Updated: 2021/01/13 19:53:18 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void			start_eating(int id)
{
	struct timeval	tval;

	gettimeofday(&tval, NULL);
	printf("%d %d is eating\n", tval.tv_usec, id + 1);
	usleep(g_time_to_eat * 1000);
}