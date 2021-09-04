/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 10:58:19 by hgrissen          #+#    #+#             */
/*   Updated: 2021/08/31 12:25:50 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_philo.h"

void	timer(int t)
{
	uint64_t	start;
	uint64_t	time_diff;

	start = get_time() * 1000;
	while (1)
	{
		time_diff = t - (get_time() * 1000 - start);
		if (time_diff < 50)
		{
			usleep(time_diff);
			break ;
		}
		if (time_diff > (uint64_t)t)
			break ;
		usleep(50);
	}
}

uint64_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
