/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:18:21 by rihoy             #+#    #+#             */
/*   Updated: 2024/05/06 17:43:02 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	init_philo(t_philo_data *if_tb)
{
	int	id;

	id = -1;
	if_tb->philo_man = malloc(sizeof(t_philosophe) * if_tb->nbr_philo);
	if (!if_tb->philo_man)
	{
		printf_error(RED"Error: malloc failed\n");
		return (false);
	}
	while (++id < if_tb->nbr_philo)
	{
		if (init_man(&if_tb->philo_man[id]))
		{
			return (false);
		}
		if (id == if_tb->nbr_philo - 1)
			if_tb->philo_man[id].right_fork = if_tb->philo_man[0].left_fork;
		else
			if_tb->philo_man[id].right_fork = if_tb->philo_man[id + 1].left_fork;
	}
	return (true);
}

bool	init_man(t_philosophe *philo)
{
	philo->id = 0;
	philo->time = 0;
	philo->last_meal = 0;
	philo->philo_thread = malloc(sizeof(pthread_t));
	if (!philo->philo_thread)
	{
		printf_error(RED"Error: malloc failed\n"RST);
		return (false);
	}
	if (pthread_mutex_init(philo->left_fork, NULL))
	{
		printf_error(RED"Error: mutex init failed\n");
		return (false);
	}
	if (pthread_mutex_init(philo->die, NULL))
	{
		printf_error(RED"Error: mutex init failed\n");
		return (false);
	}
	return (true);
}
