/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:45:09 by rihoy             #+#    #+#             */
/*   Updated: 2024/05/03 12:48:24 by rihoy            ###   ########.fr       */
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

# define PHILO 1
# define FORK 2

typedef struct s_philosophe	t_philosophe;

typedef struct s_philo_data
{
	int				nbr_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_eat;
	t_philosophe	*philo;
}	t_philo_data;

typedef struct s_philosophe
{
	int				id;
	pthread_t		*philo_thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	die;
	useconds_t		last_meal;
	useconds_t		time;
}	t_philosophe;
// init philo
bool	init_philo(t_philo_data *if_tb);
// routine philo
void	routine_philo(void *philo);

#endif