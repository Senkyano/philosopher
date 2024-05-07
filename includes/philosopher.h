/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:45:09 by rihoy             #+#    #+#             */
/*   Updated: 2024/05/07 18:10:58 by rihoy            ###   ########.fr       */
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

# define BLK "\e[0;90m"
# define RED "\e[1;31m"
# define GR "\e[1;92m"
# define Y "\e[1;93m"
# define BLU "\e[1;94m"
# define PUR "\e[1;95m"
# define CY "\e[1;96m"
# define WH "\e[0;97m"
# define RST "\e[0m"

typedef struct s_philosophe	t_philosophe;

typedef struct s_philo_data
{
	int				nbr_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_eat;
	pthread_t		admin_thread;//malloc
	pthread_mutex_t	die;//mutex
	t_philosophe	*philo_man;//malloc nbr_philo
}	t_philo_data;

typedef struct s_philosophe
{
	int				id;
	pthread_t		philo_thread;//malloc
	pthread_mutex_t	left_fork;//mutex
	pthread_mutex_t	*right_fork;
	suseconds_t		last_meal;
	suseconds_t		time;
}	t_philosophe;

// init philo
bool	init_philo(t_philo_data *if_tb);
// routine philo
void	*routine_philo(void *philo);
void	*admin_philo(void *data_info);
// free philo
void	free_philosophe(t_philo_data *table);

#endif