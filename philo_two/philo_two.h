/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 13:32:12 by ielbadao          #+#    #+#             */
/*   Updated: 2021/02/28 15:07:15 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TOW_H
# define PHILO_TOW_H
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <semaphore.h>

typedef char	*t_string;

int				g_philo_num;
int				g_time_to_eat;
int				g_time_to_sleep;
int				g_time_to_die;
int				g_number_of_times_of_eat;

void			ft_putnbr(long n);
int				ft_atoi(t_string number);
void			println(t_string str);
#endif
