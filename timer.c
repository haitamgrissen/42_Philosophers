/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 10:58:19 by hgrissen          #+#    #+#             */
/*   Updated: 2021/08/30 17:20:00 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lib_philo.h"

void    timer(int t)
{
       t = 0;
}

uint64_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}