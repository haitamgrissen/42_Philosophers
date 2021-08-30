/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 10:12:27 by hgrissen          #+#    #+#             */
/*   Updated: 2021/08/30 16:52:38 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lib_philo.h"

/*
void	supervisor(t_args *args)
{
	args->n_of_meals =0; ///to silence unused error 
}



*/
void		create_threads(t_sim	*sim)
{
	int			i;
	pthread_t	tmp[sim->args->n_of_philos];
	
	i = 0;
	while (i < sim->args->n_of_philos)
	{
		pthread_create(tmp + i, NULL, &routine, &sim->philos[i]);
		i += 2;
	}
	usleep(100);
	i = 1;
	while (i < sim->args->n_of_philos)
	{
		pthread_create(tmp + i, NULL, &routine, &sim->philos[i]);
		i += 2;
	}
//

}






int     main(int argc, char **argv)
{
	t_sim		*sim;
	
	if (argc < 5 || argc > 6)
		print_error();
	sim = init_sim(argc, argv);


	create_threads(sim);
	//start supervisor
	
	while(1);
	
	
	// print args 

/*	int i = 0;
	while (i < sim->args->n_of_philos)
	{
		printf("the philo N : %d left f : %d right f : %d\n", sim->philos[i].id, sim->philos[i].leftfork, sim->philos[i].rightfork);
		printf("----n of philos : %d\n----t to die : %d\n----t to eat : %d\n----t to slp : %d\n", sim->philos[i].args->n_of_philos, sim->philos[i].args->t_to_die, sim->philos[i].args->t_to_eat, sim->philos[i].args->t_to_slp);
		printf("----n of meals : %d\n", sim->philos[i].args->n_of_meals);
		i++;
	} */
	
	
	/* printf("n of philos : %d\nt to die : %d\nt to eat : %d\nt to slp : %d\n", args->n_of_philos, args->t_to_die, args->t_to_eat,args->t_to_slp);
	printf("number of meals : %d\n", args->n_of_meals); */




/*
	free shit
*/
	return (0);
}