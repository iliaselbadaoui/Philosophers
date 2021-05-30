/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 20:46:26 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/30 18:02:13 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	philo_state(int state, t_args *args)
{
	int				done_printing;

	done_printing = 0;
	if (args->philo->died)
		return ;
	while (!done_printing)
	{
		pthread_mutex_lock(&args->philo->protect_output);
		ft_putnbr(get_timestamp());
		println(" ", 1);
		done_printing = 1;
		ft_putnbr(args->id + 1);
		if (state == FORK_TAKEN)
			println("\033[0;34m has taken a fork\033[0m\n", 1);
		else if (state == EATING)
			println("\033[0;32m is eating\033[0m\n", 1);
		else if (state == SLEEPING)
			println("\033[0;35m is sleeping\033[0m\n", 1);
		else if (state == THINKING)
			println("\033[0;36m is thinking\033[0m\n", 1);
		else if (state == DIED)
			println("\033[0;31m died\033[0m\n", 1);
		pthread_mutex_unlock(&args->philo->protect_output);
	}
}
