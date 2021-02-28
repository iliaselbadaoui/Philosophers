/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 13:32:23 by ielbadao          #+#    #+#             */
/*   Updated: 2021/02/28 15:06:14 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static int		error_handler(int argc, t_string *argv)
{
	if (argc < 5 || argc > 6)
	{
		println("There must be 5 or 6 Args");
		return (0);
	}
	return (1);
}

int				main(int argc, t_string *argv)
{
	if (error_handler(argc, argv))
		return (1);
	return (0);
}
