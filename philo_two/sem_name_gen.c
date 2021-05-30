/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_name_gen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 18:42:18 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/30 09:59:38 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo_two.h"

static int		integer_length(int nb)
{
	int		len;

	len = 1;
	if (nb < 0)
	{
		len++;
		nb *= -1;
	}
	while (nb / 10)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static int		power(int base, int power)
{
	int	res;

	res = 1;
	while (power > 0)
	{
		res *= base;
		power--;
	}
	return (res);
}

static t_string	integer_to_string(int nb)
{
	int			len;
	int			pow;
	t_string	res;
	int			i;

	len = integer_length(nb);
	res = (t_string)malloc(len + 1);
	res[len] = '\0';
	i = 0;
	pow = power(10, len - 1);
	if (nb < 0)
	{
		res[0] = '-';
		pow = power(10, len - 2);
		nb *= -1;
		i = 1;
	}
	while (i < len)
	{
		res[i] = '0' + nb / pow;
		nb = nb % pow;
		pow /= 10;
		i++;
	}
	return (res);
}

t_string		sema_name_gen()
{
	t_string	name;
	t_string	number;
	int			i;
	int			j;
	static int	count;

	i = 5;
	j = 0;
	name = (t_string)malloc(integer_length(count) + 6);
	number = integer_to_string(count);
	name[0] = 's';
	name[1] = 'e';
	name[2] = 'm';
	name[3] = 'a';
	name[4] = '_';
	while (i < integer_length(count) + 6)
	{
		name[i++]	= number[j++];
	}
	free(number);
	number = NULL;
	name[i] = '\0';
	count++;
	return (name);
}
