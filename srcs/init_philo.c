/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:18:21 by rihoy             #+#    #+#             */
/*   Updated: 2024/05/03 12:17:08 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	init_philo(t_philo_data *if_tb)
{
	int	id;

	id = -1;
	if_tb->philo = malloc(sizeof(t_philosophe) * if_tb->nbr_philo);
	if (!if_tb->philo)
	{
		printf_error(RED"Error: malloc failed\n");
		return (false);
	}
	while (++id < if_tb->nbr_philo)
	{
		if_tb->philo[id].id = id;
		if_tb->philo[id].time = 0;
		if_tb->philo[id].last_meal = 0;
		if (pthread_mutex_init(if_tb->philo[id].left_fork, NULL))
		{
			printf_error(RED"Error: mutex init failed\n");
			return (false);
		}
		if (id == if_tb->nbr_philo - 1)
			if_tb->philo[id].right_fork = if_tb->philo[0].left_fork;
		else
			if_tb->philo[id].right_fork = if_tb->philo[id + 1].left_fork;
	}
	return (true);
}
