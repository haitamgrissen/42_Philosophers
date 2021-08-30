/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 14:11:42 by hgrissen          #+#    #+#             */
/*   Updated: 2021/08/30 16:28:06 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_philo.h"




void    *routine(void *philo)
{
    while (1)
	{
        //display("has been created", philo);
        //printf("%d is created\n", ph->id);
		p_eat((t_philo *)philo);
		p_sleep((t_philo *)philo);
		p_think((t_philo *)philo);
	}
    return NULL;
}




void    p_eat(t_philo *philo)
{
    pthread_mutex_lock(&philo->sim->forks[philo->leftfork]);
    display("has taken left fork", philo);
    pthread_mutex_lock(&philo->sim->forks[philo->rightfork]);
    display("has taken right fork", philo);
    pthread_mutex_lock(&philo->iseating);
    philo->lastmeal = 0;//gettimeofday function
    display("is eating", philo);
    usleep(philo->args->t_to_eat);// - 14000);
   // while (1);// timeofday - lastmeal < time to eat
    pthread_mutex_unlock(&philo->iseating);
    pthread_mutex_unlock(&philo->sim->forks[philo->leftfork]);
    pthread_mutex_unlock(&philo->sim->forks[philo->rightfork]);
}

void    p_sleep(t_philo *philo)
{
    display("is sleeping", philo);
    usleep(philo->args->t_to_slp * 100);// - 14000);
    //while (1);// timeofday - lastmeal < time to eat
}

void    p_think(t_philo *philo)
{
    display("is thinking", philo);
}