/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:34:36 by rihoy             #+#    #+#             */
/*   Updated: 2024/05/15 14:35:26 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	take_fork(t_philosophe *thinkeur, pthread_mutex_t *fork)
{
	pthread_mutex_lock(fork);
	if (condition_die(thinkeur))
		return (pthread_mutex_unlock(fork), false);
	if (!print_time("has taken a fork", thinkeur))
		return (pthread_mutex_unlock(fork), false);
	return (true);
}

bool	eating(t_philosophe *thinkeur)
{
	if (thinkeur->id != 0)
	{
		if (!take_fork(thinkeur, &thinkeur->left_fork))
			return (false);
		if (!take_fork(thinkeur, thinkeur->right_fork))
			return (pthread_mutex_unlock(&thinkeur->left_fork), false);
	}
	else
	{
		if (!take_fork(thinkeur, thinkeur->right_fork))
			return (false);
		if (!take_fork(thinkeur, &thinkeur->left_fork))
			return (pthread_mutex_unlock(thinkeur->right_fork), false);
	}
	if (!print_time("is eating", thinkeur))
	{
		pthread_mutex_unlock(&thinkeur->left_fork);
		return (pthread_mutex_unlock(thinkeur->right_fork), false);
	}
	thinkeur->add_eat++;
	usleep(thinkeur->data->time_to_eat * 1000);
	pthread_mutex_unlock(&thinkeur->left_fork);
	return (pthread_mutex_unlock(thinkeur->right_fork), true);
}

bool	sleeping(t_philosophe *thinkeur)
{
	long	time;

	pthread_mutex_lock(&thinkeur->data->die);
	if (thinkeur->data->one_dead)
		return (pthread_mutex_unlock(&thinkeur->data->die), false);
	pthread_mutex_unlock(&thinkeur->data->die);
	time = actual_time();
	if (time == -1)
		return (false);
	time = time - thinkeur->data->start_time;
	printf("%ld %d is sleeping\n", time, thinkeur->id);
	usleep(thinkeur->data->time_to_sleep * 1000);
	pthread_mutex_lock(&thinkeur->data->die);
	if (thinkeur->data->one_dead)
		return (pthread_mutex_unlock(&thinkeur->data->die), (false));
	pthread_mutex_unlock(&thinkeur->data->die);
	time = actual_time();
	if (time == -1)
		return (false);
	time = time - thinkeur->data->start_time;
	printf("%ld %d is thinking\n", time, thinkeur->id);
	return (true);
}

bool	quota_eat(t_philosophe *thinkeur)
{
	if (thinkeur->data->nbr_eat == -1)
		return (false);
	else if (thinkeur->add_eat == thinkeur->data->nbr_eat)
		return (true);
	return (false);
}
