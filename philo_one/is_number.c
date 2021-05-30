/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 18:24:04 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/30 17:59:27 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

t_bool	is_number(t_string nbr)
{
	if (*nbr == '-' || *nbr == '+')
		nbr++;
	while (*nbr)
	{
		if (*nbr < '0' || *nbr > '9')
			return (false);
		nbr++;
	}
	return (true);
}
