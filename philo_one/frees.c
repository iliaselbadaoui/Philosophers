/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 08:46:07 by ielbadao          #+#    #+#             */
/*   Updated: 2021/02/14 20:14:27 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void			frees(void)
{
	free(g_thread);
	free(g_ids);
	free(g_forks);
	free(g_philos);
	free(g_times);
	pthread_mutex_destroy(&g_mutex);
	pthread_mutex_destroy(&g_protect_output);
}
