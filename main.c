/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 10:12:27 by hgrissen          #+#    #+#             */
/*   Updated: 2021/07/28 20:37:36 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lib_philo.h"


void	supervisor(t_args *args)
{
	
}

void		*routine(void *philo)
{
	while (1)
	{
		eat((t_philo *)philo);
		sleep((t_philo *)philo);
		think((t_philo *)philo);
	}
}


void		initl7za9(t_sim	*sim)
{
	int			i;
	pthread_t	tmp;
	
	i = 0;
	while (i < sim->philos->args->n_of_philos)
	{
		pthread_create(tmp, NULL, &routine, &sim->philos[i]);
		i++;
	}
}

t_philo		*init_philos(t_args *args)
{
	int			i;
	t_philo		*philos;

	if (!(philos = (t_philo *)malloc(sizeof(t_philo) * args->n_of_philos)))
		return (NULL);
	i = 0;
	while (i < args->n_of_philos)
	{
		philos[i].id = i + 1;
		philos[i].leftfork = i;
		philos[i].rightfork = (i + 1) % args->n_of_philos;
		philos[i].meals = 0;
		philos[i].iseating = 0;
		philos[i].lastmeal = 0;
		philos[i].args = args;
		i++;
	}
	return (philos);
}

int     main(int argc, char **argv)
{
	t_args		*args;
	t_sim		*sim;
	if (!(sim = (t_sim *)malloc((sizeof(t_sim)))))
		exit(0);
	if (argc < 5 || argc > 6)
		print_error();
	args = parse(argc, argv);
	sim->philos = init_philos(args);
	
	//start supervisor
	
/* 	int i = 0;
	while (i < args->n_of_philos)
	{
		printf("the philo N : %d left f : %d right f : %d\n", sim->philos[i].id, sim->philos[i].leftfork, sim->philos[i].rightfork);
		printf("----n of philos : %d\n----t to die : %d\n----t to eat : %d\n----t to slp : %d\n", sim->philos[i].args->n_of_philos, sim->philos[i].args->t_to_die, sim->philos[i].args->t_to_eat, sim->philos[i].args->t_to_slp);
		printf("----n of meals : %d\n", sim->philos[i].args->n_of_meals);
		i++;
	} */
	
	
	/* printf("n of philos : %d\nt to die : %d\nt to eat : %d\nt to slp : %d\n", args->n_of_philos, args->t_to_die, args->t_to_eat,args->t_to_slp);
	printf("number of meals : %d\n", args->n_of_meals); */
	free (args);
	return (0);
}