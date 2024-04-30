/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:45:09 by rihoy             #+#    #+#             */
/*   Updated: 2024/04/30 14:17:22 by rihoy            ###   ########.fr       */
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
	pthread_mutex_t	die;
}	t_philo_data;

typedef struct s_philosophe
{
	int				id;
	pthread_t		philo_thread;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	*right_fork;
	useconds_t		last_meal;
	useconds_t		time;
}	t_philosophe;

#endif