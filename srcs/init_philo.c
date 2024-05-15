/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:18:21 by rihoy             #+#    #+#             */
/*   Updated: 2024/05/15 17:12:56 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"



bool	init_philo(int id, t_table *data, t_philo *philo)
{
	philo->id = id;
	philo->data = data;
	philo->nbr_eat = 0;
	philo->last_meal = 0;
	philo->philo_thread = 0;
	if (pthread_mutex_init(&philo->left_fork, NULL) != 0)
		return (printf(RED"Error: mutex init failed\n"RST), false);
	if (id != data->nbr_philo - 1)
		philo->right_fork = &data->man[id + 1].left_fork;
	else if (data->nbr_philo != 1 && id == data->nbr_philo - 1)
		philo->right_fork = &data->man[0].left_fork;
	return (true);
}

void	free_all_philo(int i, t_table *data)
{
	while (i >= 0)
	{
		pthread_mutex_destroy(&data->man[i].left_fork);
		i--;
	}
	free(data->man);
}

