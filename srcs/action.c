/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:34:36 by rihoy             #+#    #+#             */
/*   Updated: 2024/05/10 17:56:16 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	condition_die(t_philosophe *thinkeur)
{
	long	time;

	pthread_mutex_lock(&thinkeur->data->die);
	if (thinkeur->data->one_dead)
		return (pthread_mutex_unlock(&thinkeur->data->die), true);
	time = actual_time() - thinkeur->data->start_time - thinkeur->last_meal;
	if (thinkeur->data->time_to_die < time)
	{
		printf(RED"%ld %d died\n"RST, time, thinkeur->id);
		thinkeur->data->one_dead = true;
		pthread_mutex_unlock(&thinkeur->data->die);
		return (true);
	}
	pthread_mutex_unlock(&thinkeur->data->die);
	return (false);
}

bool	take_fork(t_philosophe *thinkeur, pthread_mutex_t *fork)
{
	long	time;
	long	time_check;

	pthread_mutex_lock(fork);
	time_check = actual_time();
	if (time_check == -1)
		return (pthread_mutex_unlock(fork), false);
	time = time_check - thinkeur->data->start_time;
	printf("%ld %d has taken a fork\n", time, thinkeur->id);
	return (true);
}

bool	eating(t_philosophe *thinkeur)
{
	long	time;

	if (thinkeur->id != 0)
	{
		if (!take_fork(thinkeur, &thinkeur->left_fork))
			return (false);
		if (!take_fork(thinkeur, thinkeur->right_fork))
			return (false);
	}
	else
	{
		if (!take_fork(thinkeur, thinkeur->right_fork))
			return (false);
		if (!take_fork(thinkeur, &thinkeur->left_fork))
			return (false);
	}
	time = actual_time();
	if (time == -1)
		return (false);
	time = time - thinkeur->data->start_time;
	printf("%ld %d is eating\n", time, thinkeur->id);
	thinkeur->add_eat++;
	thinkeur->last_meal = time;
	usleep(thinkeur->data->time_to_eat * 1000);
	pthread_mutex_unlock(&thinkeur->left_fork);
	pthread_mutex_unlock(thinkeur->right_fork);
	return (true);
}

bool	sleeping(t_philosophe *thinkeur)
{
	long	time;

	pthread_mutex_lock(&thinkeur->data->die);
	if (thinkeur->data->one_dead)
		return (false);
	pthread_mutex_unlock(&thinkeur->data->die);
	time = actual_time();
	if (time == -1)
		return (false);
	time = time - thinkeur->data->start_time;
	printf("%ld %d is sleeping\n", time, thinkeur->id);
	usleep(thinkeur->data->time_to_sleep * 1000);
	pthread_mutex_lock(&thinkeur->data->die);
	if (thinkeur->data->one_dead)
		return (false);
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
