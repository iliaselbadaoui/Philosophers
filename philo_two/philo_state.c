/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 18:18:50 by ielbadao          #+#    #+#             */
/*   Updated: 2021/02/28 20:13:23 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void			philo_state(int state, int philo_id)
{
	struct timeval	tval;
	int				done_printing;

	done_printing = 0;
	gettimeofday(&tval, NULL);
	while (!done_printing)
	{
		if (sem_wait(g_output))
			return;
		ft_putnbr(tval.tv_sec * 1000 + tval.tv_usec / 1000);
		println(" ");
		done_printing = 1;
		ft_putnbr(philo_id);
		if (state == FORK_TAKEN)
			println("\033[0;34m has taken a fork\033[0m\n");
		else if (state == EATING)
			println("\033[0;32m is eating\033[0m\n");
		else if (state == SLEEPING)
			println("\033[0;35m is sleeping\033[0m\n");
		else if (state == THINKING)
			println("\033[0;36m is thinking\033[0m\n");
		else if (state == DIED)
			println("\033[0;31m died\033[0m\n");
		sem_post(g_output);
	}
}
