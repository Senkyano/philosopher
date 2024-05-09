/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:00:34 by rihoy             #+#    #+#             */
/*   Updated: 2024/05/09 16:05:43 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	eating(t_philosophe *thinkeur)
{
	long	time;

	if (thinkeur->id == 1)
	{
		pthread_mutex_lock(thinkeur->right_fork);
		printf("%ld %d has taken a fork\n", actual_time() - thinkeur->data->start_time, thinkeur->id);
		pthread_mutex_lock(&thinkeur->left_fork);
	}
	else
	{
		pthread_mutex_lock(&thinkeur->left_fork);
		printf("%ld %d has taken a fork\n", actual_time() - thinkeur->data->start_time, thinkeur->id);
		pthread_mutex_lock(thinkeur->right_fork);
	}
	printf("%ld %d has taken a fork\n", actual_time() - thinkeur->data->start_time, thinkeur->id);
	time = actual_time() - thinkeur->data->start_time;
	if (time == -1)
		return (false);
	thinkeur->last_meal = time;
	thinkeur->add_eat++;
	printf("%ld %d is eating\n", time, thinkeur->id);
	usleep(thinkeur->data->time_to_eat * 1000);
	pthread_mutex_unlock(&thinkeur->left_fork);
	pthread_mutex_unlock(thinkeur->right_fork);
	return (true);
}

bool	sleeping(t_philosophe *thinkeur)
{
	long	time;

	time = actual_time() - thinkeur->data->start_time;
	if (time == -1)
		return (false);
	printf("%ld %d is sleeping\n", time, thinkeur->id);
	usleep(thinkeur->data->time_to_sleep * 1000);
	time = actual_time() - thinkeur->data->start_time;
	if (time == -1)
		return (false);
	printf("%ld %d is thinking\n", time, thinkeur->id);
	return (true);
}
