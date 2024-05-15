/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 22:34:16 by rihoy             #+#    #+#             */
/*   Updated: 2024/05/15 12:40:24 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	start_routine(t_philosophe *thinkeur);
long	actual_time(void);

void	*routine_philo(void *philo)
{
	t_philosophe	*thinkeur;

	thinkeur = (t_philosophe *)philo;
	if (!start_routine(thinkeur))
		return (NULL);
	while (1)
	{
		if (condition_die(thinkeur))
			return (NULL);
		if (!eating(thinkeur))
			return (NULL);
		if (quota_eat(thinkeur))
			break ;
		if (!sleeping(thinkeur))
			return (NULL);
	}
	return (NULL);
}

bool	start_routine(t_philosophe *thinkeur)
{
	long	time;

	time = actual_time() - thinkeur->data->start_time;
	if (time == -1)
		return (false);
	if (thinkeur->data->nbr_philo == 1)
	{
		printf("%ld %d has taken a fork\n", time, thinkeur->id);
		usleep(thinkeur->data->time_to_die * 1000);
		time = actual_time() - thinkeur->data->start_time;
		if (time == -1)
			return (false);
		printf("%ld %d died\n", time, thinkeur->id);
		return (false);
	}
	if (thinkeur->id % 2 == 0)
	{
		printf("%ld %d is thinking\n", time, thinkeur->id);
		usleep(thinkeur->data->time_to_eat * 1000);
	}
	return (true);
}

long	actual_time(void)
{
	struct timeval	tv;
	time_t			secondes;
	suseconds_t		microsecondes;
	long			time;

	if (gettimeofday(&tv, NULL) == -1)
	{
		printf(RED"Error: gettimeofday failed\n"RST);
		return (-1);
	}
	secondes = tv.tv_sec;
	microsecondes = tv.tv_usec;
	time = secondes * 1000 + microsecondes / 1000;
	return (time);
}
