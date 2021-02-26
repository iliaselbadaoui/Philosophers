/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 13:28:30 by ielbadao          #+#    #+#             */
/*   Updated: 2021/02/26 18:52:29 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

// static char	*char_to_str(char c)
// {
// 	char	*arr = (char *)malloc(2);
// 	arr[0] = c;
// 	arr[1] = '\0';
// 	return arr;
// }

void		init_forks(void)
{
	int		i;

	i = 0;
	g_forks = (int *)malloc(sizeof(int) * g_philo_num);
	g_philos = (int *)malloc(sizeof(int) * g_philo_num);
	g_times = (int *)malloc(sizeof(int) * g_philo_num);
	g_times_compare = (int *)malloc(sizeof(int) * g_philo_num);
	while (i < g_philo_num)
	{
		g_philos[i] = 0;
		g_forks[i] = 0;
		g_times[i] = 0;
		g_times_compare[i] = 0;
		i++;
	}
}
