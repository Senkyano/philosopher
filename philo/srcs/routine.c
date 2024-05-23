/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 22:34:16 by rihoy             #+#    #+#             */
/*   Updated: 2024/05/23 12:26:46 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	who_start(t_philo *philo);

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->data->create);
	while (1 && !philo->data->admin_ready)
	{
		pthread_mutex_unlock(&philo->data->create);
		usleep(100);
		if (philo->data->one_dead)
			return (pthread_mutex_unlock(&philo->data->create), NULL);
		pthread_mutex_lock(&philo->data->create);
	}
	pthread_mutex_unlock(&philo->data->create);
	if (!who_start(philo))
		return (NULL);
	while (1)
	{
		if (!taking_fork(philo))
			return (NULL);
		if (!eating_pasta(philo))
			return (NULL);
		if (!sleeping(philo))
			return (NULL);
	}
	return (NULL);
}

bool	who_start(t_philo *philo)
{
	if (philo->data->nbr_philo == 1)
	{
		if (print_action("has taken fork", philo))
			return (false);
		if (usleep(philo->data->time_to_die * 1000) != 0)
			return (false);
		return (false);
	}
	if (philo->id % 2 == 0)
	{
		if (!print_action("is thinking", philo))
			return (false);
		if (usleep(philo->data->time_to_eat * 1000) != 0)
			return (false);
	}
	return (true);
}
