/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_manager.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 18:17:25 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/03 16:39:39 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void			*philosophers_manager(void *id_arg)
{
	int		*id;

	id = (int *) id_arg;
	while (!g_died)
	{
		take_forks(*id);
		eat(*id);
		philo_sleep(*id);
		think(*id);
	}
	return (NULL);
}
