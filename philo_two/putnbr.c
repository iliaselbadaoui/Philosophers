/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 09:51:27 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/18 12:16:16 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void			ft_putnbr(long n)
{
	long		nb;

	nb = n;
	if (n < 0)
	{
		ft_putchar('-');
		nb = n * -1;
	}
	if (nb > 10)
	{
		ft_putnbr((nb / 10));
		ft_putchar((nb % 10) + '0');
	}
	else
		ft_putchar((nb + '0'));
}
