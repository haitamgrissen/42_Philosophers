/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 14:07:19 by hgrissen          #+#    #+#             */
/*   Updated: 2021/07/28 20:26:21 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_philo.h"

void    display(char *msg, t_sim *sim)
{
	uint64_t time;
	time = 0;
	pthread_mutex_lock(sim->print);
	printf("%llu philosopher %d %s\n", time, sim->philos->id, msg);
	if (ft_strcmp(msg, "died"))
		pthread_mutex_unlock(sim->print);
}