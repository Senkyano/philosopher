/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:45:09 by rihoy             #+#    #+#             */
/*   Updated: 2024/05/16 14:48:22 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include "lib_utils.h"
# include <stdbool.h>

# define PHILO 1
# define FORK 2

# define BLK "\e[0;90m"
# define RED "\e[1;31m"
# define GR "\e[1;92m"
# define Y "\e[1;93m"
# define BLU "\e[1;94m"
# define PUR "\e[1;95m"
# define CY "\e[1;96m"
# define WH "\e[0;97m"
# define RST "\e[0m"

//max on peut avoir 18676 threads

typedef struct s_philo	t_philo;

typedef struct s_table
{
	int				nbr_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				tot_eat;
	long			start_time;
	int				all_create;
	int				one_dead;
	int				admin_ready;
	pthread_t		admin_thread;
	pthread_mutex_t	die;
	pthread_mutex_t	write;
	t_philo			*man;
}	t_table;

typedef struct s_philo
{
	int				nbr_eat;
	int				id;
	pthread_t		philo_thread;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	*right_fork;
	long			last_meal;
	t_table			*data;
}	t_philo;

//main
long	actual_time(void);
//init_philo
bool	init_philo(int id, t_table *data, t_philo *philo);
void	free_all_philo(int i, t_table *data);
//admin 
void	*admin(void *arg);
int		check_death(t_philo *philo);
//liberation
void	wait_threads(t_table *data);
//routine
void	*philo_routine(void *arg);
//action
bool	print_action(char *str, t_philo *philo);
bool	taking_fork(t_philo *philo);
bool	eating_pasta(t_philo *philo);
bool	sleeping(t_philo *philo);

#endif