/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:30:27 by ielbadao          #+#    #+#             */
/*   Updated: 2021/01/14 11:58:09 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

pthread_t			create_philo(void *(func(void *arg)), int *id)
{
	pthread_t	thread;

	pthread_create(&thread, NULL, func, (void *)id);
	return (thread);
}
