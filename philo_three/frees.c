/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 08:46:07 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/08 10:41:16 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void			frees(void)
{
	free(g_thread);
	free(g_ids);
	free(g_philos);
	free(g_times);
	sem_unlink("FORKS");
	sem_unlink("FORKS_PROTECT");
	sem_unlink("OUTPUT_PROTECT");
}
