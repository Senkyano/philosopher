/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:45:09 by rihoy             #+#    #+#             */
/*   Updated: 2024/04/27 20:44:15 by rihoy            ###   ########.fr       */
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

typedef struct s_philo_data
{
	int				nbr_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_eat;
}	t_philo_data;

typedef struct s_thinkeur
{
	int					id;
	pthread_t			philosopher;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*left_fork;
	s_thinkeur			*next;
} t_thinkeur;

#endif