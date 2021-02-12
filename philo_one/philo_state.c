/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 10:46:26 by ielbadao          #+#    #+#             */
/*   Updated: 2021/02/12 17:53:05 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void			philo_state(int state, int philo_id)
{
	struct timeval	tval;
	int				done_printing;

	done_printing = 0;
	gettimeofday(&tval, NULL);
	while (!done_printing)
	{
		pthread_mutex_lock(&g_protect);
		done_printing = 1;
		ft_putnbr(tval.tv_sec * 1000 + tval.tv_usec / 1000);
		println(" ");
		ft_putnbr(philo_id);
		if (state == FORK_TAKEN)
			println(" has taken a fork\n");
		else if (state == EATING)
			println(" is eating\n");
		else if (state == SLEEPING)
			println(" is sleeping\n");
		else if (state == THINKING)
			println(" is thinking\n");
		else if (state == DIED)
			println(" died\n");
		pthread_mutex_unlock(&g_protect);
	}
}
