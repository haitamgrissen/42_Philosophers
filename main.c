/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 10:12:27 by hgrissen          #+#    #+#             */
/*   Updated: 2021/09/03 15:21:08 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_philo.h"

void	deathofsocrates(t_sim *sim)
{
	free(sim->philos);
	free(sim->args);
	free(sim->forks);
	exit(0);
}

void	socrates(t_sim *sim)
{
	int			i;
	uint64_t	x;
	uint64_t	y;

	while (1)
	{
		i = 0;
		while (i < sim->args->n_of_philos)
		{
			y = (uint64_t)sim->args->t_to_die;
			x = get_time() - sim->philos[i].lastmeal;
			if (x >= y)
			{
				display("died", &sim->philos[i]);
			}
			if (sim->ate >= sim->args->n_of_meals && sim->args->n_of_meals != 0)
			{
				deathofsocrates(sim);
			}	
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	t_sim		*sim;

	if (argc < 5 || argc > 6)
		print_error();
	sim = init_sim(argc, argv);
	create_threads(sim);
	socrates(sim);
	return (0);
}
