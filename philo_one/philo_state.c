/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 10:46:26 by ielbadao          #+#    #+#             */
/*   Updated: 2021/02/09 11:08:15 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void			philo_state(int state, int philo_id)
{
	struct timeval	tval;
	
	gettimeofday(&tval, NULL);
	ft_putnbr(tval.tv_sec);
	println(" ");
	ft_putnbr(philo_id);
	if (state == FORK_TAKEN)
		println(" has taken a fork\n");
	else if (state == EATING)
		println(" is eating\n");
	else if (state == SLEEPING)
		println(" is sleeping");
	else if (state == THINKING)
		println(" is thinking\n");
	else if (state == DIED)
		println(" died\n");
}
