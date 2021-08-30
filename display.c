/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 14:07:19 by hgrissen          #+#    #+#             */
/*   Updated: 2021/08/30 16:02:02 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_philo.h"

void    display(char *msg, t_philo *philo)
{
	uint64_t time;
	time = 0;
	
	//printf("%d is created\n", philo->id);
	//printf("AAAAAAA\n");
	pthread_mutex_lock(&(philo->sim->print));

	printf("%llu philosopher %d %s\n", time, philo->id, msg);
	//if (!ft_strcmp(msg, "died"))
	pthread_mutex_unlock(&(philo->sim->print));
}