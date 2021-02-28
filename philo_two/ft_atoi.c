/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 14:44:47 by ielbadao          #+#    #+#             */
/*   Updated: 2021/02/28 14:45:02 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int				ft_atoi(char *number)
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
