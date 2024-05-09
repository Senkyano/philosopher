/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:34:36 by rihoy             #+#    #+#             */
/*   Updated: 2024/05/09 22:22:03 by rihoy            ###   ########.fr       */
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
	if (thinkeur->data->time_to_die <= time)
	{
		printf("%ld %d died\n", time, thinkeur->id);
		thinkeur->data->one_dead = true;
		pthread_mutex_unlock(&thinkeur->data->die);
		return (true);
	}
	pthread_mutex_unlock(&thinkeur->data->die);
	return (false);
}

bool	eating(t_philosophe *thinkeur)
{
	(void)thinkeur;
	return (true);
}

bool	sleeping(t_philosophe *thinkeur)
{
	(void)thinkeur;
	return (true);
}

bool	quota_eat(t_philosophe *thinkeur)
{
	(void)thinkeur;
	return (true);
}
