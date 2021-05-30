/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_timestamp copy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 09:51:46 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/30 18:08:46 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

long	get_timestamp(void)
{
	struct timeval	tval;

	gettimeofday(&tval, NULL);
	return (tval.tv_sec * 1000 + tval.tv_usec / 1000);
}
