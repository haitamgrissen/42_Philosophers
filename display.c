/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 14:07:19 by hgrissen          #+#    #+#             */
/*   Updated: 2021/09/03 15:13:22 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_philo.h"

void    display(char *msg, t_philo *philo)
{
	uint64_t time;
	time = get_time();// - (uint64_t)philo->sim->timestart;
	//time %= 10000;
	pthread_mutex_lock(&(philo->sim->print));
	printf("%llu philosopher %d %s\n", time, philo->id, msg);
	if (!ft_strcmp(msg, "died"))
	{
		//usleep(500);
		exit(0);
	}
	pthread_mutex_unlock(&(philo->sim->print));
}