/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:23:47 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/30 18:20:12 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int	ft_atoi(t_string number)
{
	int		result;
	int		sign;

	if (!number)
		return (0);
	result = 0;
	while (*number == ' ')
		number++;
	sign = 1;
	if (*number == '-')
	{
		number++;
		sign = -1;
	}
	if (*number == '+')
		number++;
	while (*number >= '0' && *number <= '9')
	{
		result *= 10;
		result += *number - '0';
		number++;
	}
	return (result * sign);
}
