/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:32:31 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/30 16:13:10 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void ft_usleep(int span)
{
	struct timeval	tv1;
	struct timeval	tv2;
	int				diff;;
	
	gettimeofday(&tv1, NULL);
	while (1)
	{
		gettimeofday(&tv2, NULL);
		diff = span - (tv2.tv_usec - tv1.tv_usec + (tv2.tv_sec - tv1.tv_sec) * 1000000);
		if (diff < 0)
			break;
		if ( diff < 50)
		{
			usleep(diff);
			break;
		}
		usleep(50);
	}
}
