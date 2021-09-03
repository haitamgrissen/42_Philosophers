/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_philo.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 10:07:45 by hgrissen          #+#    #+#             */
/*   Updated: 2021/09/01 13:51:44 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #ifndef LIB_PHILO_H
 # define LIB_PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
#include <unistd.h>
# include <sys/time.h>




typedef struct 			s_sim 	t_sim;
typedef struct 			s_philo	t_philo;
typedef struct			s_args	t_args;


struct 					s_args
{
	int		n_of_philos;
	int		t_to_die;
	int		t_to_eat;
	int		t_to_slp;
	int		n_of_meals;
	t_philo	*philos;
	
};



struct 					s_philo
{
	int					id;
	int					leftfork;
	int					rightfork;
	int					meals;
	pthread_mutex_t		iseating;
	uint64_t			lastmeal;
	t_args				*args;
	t_sim				*sim;
	int					eat_lock;
};

struct 					s_sim
{
	pthread_mutex_t		*forks;
	pthread_mutex_t		*print_mutex;
	pthread_mutex_t		print;
	t_philo				*philos;
	t_args				*args;
	uint64_t			timestart;
};

void					print_error();
t_args					*parse(int argc, char	**argv);


/*
	libft funcs
*/

int						isdigits(const char *str);
int						isdigit(int c);
int						ft_atoi(const char *str);
int						ft_strcmp(char *s1, char *s2);

/*
	inits
*/
t_sim					*init_sim(int    argc, char **argv);
pthread_mutex_t			*initforks(t_sim	*sim);
t_philo					*init_philos(t_sim	*sim);
void					create_threads(t_sim	*sim);

/*
	routines 
*/

void					*routine(void *philo);
void					p_sleep(t_philo *philo);
void					p_eat(t_philo *philo);
void					p_think(t_philo *philo);

/*
	time and sleep funcs
*/

uint64_t				get_time(void);
void					timer(int t);

void					display(char *msg, t_philo *philo);

void					socrates(t_sim *sim);

 #endif