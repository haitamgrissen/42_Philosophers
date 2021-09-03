/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 14:11:42 by hgrissen          #+#    #+#             */
/*   Updated: 2021/09/03 15:11:42 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_philo.h"

void    *routine(void *philo)
{
    t_philo     *casted;
    
    casted = philo;
    casted->lastmeal = get_time();
    while (1)
	{
		p_eat(casted);
		p_sleep(casted);
		p_think(casted);
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
    display("is eating", philo);
    timer(philo->args->t_to_eat * 1000);
    philo->lastmeal = get_time();
    //usleep(1000);
    philo->meals++;
    if ((philo->meals >= philo->args->n_of_meals))
        philo->sim->ate++;
    pthread_mutex_unlock(&philo->iseating);
    pthread_mutex_unlock(&philo->sim->forks[philo->leftfork]);
    pthread_mutex_unlock(&philo->sim->forks[philo->rightfork]);
}

void    p_sleep(t_philo *philo)
{
    display("is sleeping", philo);
    //usleep(1000);// - 14000);
    timer(philo->args->t_to_slp * 1000);
    //while (1);// timeofday - lastmeal < time to eat
}

void    p_think(t_philo *philo)
{
    display("is thinking", philo);
}