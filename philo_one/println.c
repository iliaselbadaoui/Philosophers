/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   println.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 10:48:26 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/12 18:16:14 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		println(t_string str, int fd)
{
	while (*str)
	{
		write(fd, str, 1);
		str++;
	}
}
