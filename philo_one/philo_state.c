/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 10:46:26 by ielbadao          #+#    #+#             */
/*   Updated: 2021/02/09 12:53:02 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void			output_and_change_flag(char *msg, int *print_flag)
{
	println(msg);
	*print_flag = 1;
}

void			philo_state(int state, int philo_id)
{
	struct timeval	tval;
	int				print;
	pthread_mutex_t	protect;

	print = 0;
	pthread_mutex_init(&protect, NULL);
	gettimeofday(&tval, NULL);
	ft_putnbr(tval.tv_sec);
	println(" ");
	ft_putnbr(philo_id);
	while (!print)
	{
		pthread_mutex_lock(&protect);
		if (state == FORK_TAKEN)
			output_and_change_flag(" has taken a fork\n", &print);
		else if (state == EATING)
			output_and_change_flag(" is eating\n", &print);
		else if (state == SLEEPING)
			output_and_change_flag(" is sleeping", &print);
		else if (state == THINKING)
			output_and_change_flag(" is thinking\n", &print);
		else if (state == DIED)
			output_and_change_flag(" died\n", &print);
		pthread_mutex_unlock(&protect);
	}
}
