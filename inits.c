/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 18:43:08 by hgrissen          #+#    #+#             */
/*   Updated: 2021/08/30 16:33:20 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_philo.h"

t_sim   *init_sim(int argc, char **argv)
{
    t_sim		*sim;
    
    if (!(sim = (t_sim *)malloc((sizeof(t_sim)))))
		exit(0);

    sim->args = parse(argc, argv);
	sim->philos = init_philos(sim);
	sim->forks = initforks(sim);
	
    pthread_mutex_init(&(sim->print), NULL);
	return (sim);
}

pthread_mutex_t		*initforks(t_sim	*sim)
{
	pthread_mutex_t	*forks;
	int				i;

	if (!(forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * sim->args->n_of_philos)))
		return (NULL);
	i = 0;
	while(i < sim->args->n_of_philos)
		pthread_mutex_init(&(forks[i++]), NULL);
	return forks;
}

t_philo		*init_philos(t_sim	*sim)
{
	int			i;
	t_philo		*philos;

	if (!(philos = (t_philo *)malloc(sizeof(t_philo) * sim->args->n_of_philos)))
		return (NULL);
	i = 0;
	while (i < sim->args->n_of_philos)
	{
		philos[i].id = i + 1;
		philos[i].leftfork = i;
		philos[i].rightfork = (i + 1) % sim->args->n_of_philos;
		philos[i].meals = 0;
		//philos[i].iseating = 0;
		pthread_mutex_init(&philos[i].iseating, NULL);
		philos[i].lastmeal = 0;
		philos[i].args = sim->args;
		philos[i].sim = sim;
		i++;
	}
	return (philos);
}