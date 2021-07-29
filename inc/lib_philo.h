/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_philo.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 10:07:45 by hgrissen          #+#    #+#             */
/*   Updated: 2021/07/28 20:39:09 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #ifndef LIB_PHILO_H
 # define LIB_PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_args
{
	int		n_of_philos;
	int		t_to_die;
	int		t_to_eat;
	int		t_to_slp;
	int		n_of_meals;
	t_philo	*philos;
	
}	t_args;

typedef struct s_philo
{
	int		id;
	int		leftfork;
	int		rightfork;
	int		meals;
	pthread_mutex_t		*iseating;
	int		lastmeal;
	t_args	*args;
	t_sim	*sim;
	//ptread_mutex_t	eat_lock;
}	t_philo;

typedef struct s_sim
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*print;
	t_philo			*philos;
}	t_sim;

void	print_error();
t_args		*parse(int argc, char	**argv);
int		isdigits(const char *str);
int		isdigit(int c);
int		ft_atoi(const char *str);

 #endif