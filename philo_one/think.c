/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 12:28:06 by ielbadao          #+#    #+#             */
/*   Updated: 2021/01/14 12:55:13 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void			think(int id)
{
	struct timeval	tval;

	gettimeofday(&tval, NULL);
	printf("%ld %d is thinking\n", tval.tv_sec, id + 1);
	usleep(g_time_to_sleep);
}
