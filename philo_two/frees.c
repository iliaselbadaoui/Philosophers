/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 08:46:07 by ielbadao          #+#    #+#             */
/*   Updated: 2021/02/26 17:01:43 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void			frees(void)
{
	free(g_thread);
	free(g_ids);
	free(g_forks);
	free(g_philos);
	free(g_times);
	sem_unlink("SEMAPHORE");
	sem_unlink("OUTPUT_PROTECTION");
	// sem_unlink("EATING");
}
