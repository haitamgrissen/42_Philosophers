/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 12:22:49 by hgrissen          #+#    #+#             */
/*   Updated: 2021/07/25 12:24:02 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lib_philo.h"

void	print_error()
{
	printf("argument error");
	exit (0);
}

int		check_args(int argc, char **argv)
{
	if (argv[1] && isdigits(argv[1])
		&& argv[2] && isdigits(argv[2])
		&& argv[3] && isdigits(argv[3])
		&& argv[4] && isdigits(argv[4]))
	{
		if (argc == 6 && (!argv[5] || !isdigits(argv[5])))
			return (0);	
		return (1);
	}
	else
		return (0);
}
void	check_negative(int argc, t_args *args)
{
	if (args->n_of_philos < 0
	|| args->t_to_die < 0
	||  args->t_to_eat < 0
	|| args->t_to_slp < 0)
		print_error();
	if (argc == 6 && args->n_of_meals < 0)
		print_error();
}

t_args		*parse(int argc, char	**argv)
{
	t_args	*args;

	if (!check_args(argc, argv))
		print_error();
	args = (t_args*)malloc(sizeof(t_args));
	args->n_of_philos = ft_atoi(argv[1]);
	args->t_to_die = ft_atoi(argv[2]);
	args->t_to_eat = ft_atoi(argv[3]);
	args->t_to_slp = ft_atoi(argv[4]);
	if (argc == 6)
		args->n_of_meals = ft_atoi(argv[5]);
	else
		args->n_of_meals = 0;
	check_negative(argc, args);
	return (args);
}