/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:34:36 by rihoy             #+#    #+#             */
/*   Updated: 2024/05/16 14:53:26 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	print_action(char *str, t_philo *philo)
{
	long	time;

	pthread_mutex_lock(&philo->data->write);
	time = actual_time();
	if (time == -1 || philo->data->one_dead)
	{
		philo->data->one_dead = true;
		return (pthread_mutex_unlock(&philo->data->write), false);
	}
	printf("%ld %d %s\n", time - philo->data->start_time, philo->id, str);
	pthread_mutex_unlock(&philo->data->write);
	return (true);
}

bool	taking_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	if (!print_action("has taken a fork", philo))
		return (pthread_mutex_unlock(&philo->left_fork), false);
	pthread_mutex_lock(philo->right_fork);
	if (!print_action("has taken a fork", philo))
	{
		pthread_mutex_unlock(&philo->left_fork);
		return (pthread_mutex_unlock(philo->right_fork), false);
	}
	return (true);
}

bool	eating_pasta(t_philo *philo)
{
	long	time;
	if (!print_action("is eating", philo))
		return (false);
	usleep(philo->data->time_to_eat * 1000);
	philo->nbr_eat++;
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	time = actual_time();
	if (time == -1 || philo->data->one_dead)
	{
		philo->data->one_dead = true;
		return (false);
	}
	philo->last_meal = time - philo->data->start_time;
	if (philo->data->tot_eat == philo->nbr_eat)
		return (false);
	return (true);
}

bool	sleeping(t_philo *philo)
{
	if (!print_action("is sleeping", philo))
		return (false);
	usleep(philo->data->time_to_sleep * 1000);
	print_action("is thinking", philo);
	return (true);
}
