/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   admin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 20:10:53 by rihoy             #+#    #+#             */
/*   Updated: 2024/05/15 12:28:54 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	condition_die(t_philosophe *thinkeur)
{
	long	time;

	pthread_mutex_lock(&thinkeur->data->die);
	if (thinkeur->data->one_dead)
		return (pthread_mutex_unlock(&thinkeur->data->die), true);
	time = actual_time();
	if (time == -1)
	{
		thinkeur->data->one_dead = true;
		return (pthread_mutex_unlock(&thinkeur->data->die), true);
	}
	time = time - thinkeur->data->start_time;
	if (thinkeur->data->time_to_die < time - thinkeur->last_meal)
	{
		printf(RED"%ld %d died\n"RST, time, thinkeur->id);
		thinkeur->data->one_dead = true;
		pthread_mutex_unlock(&thinkeur->data->die);
		return (true);
	}
	pthread_mutex_unlock(&thinkeur->data->die);
	return (false);
}

void	*control_admin(void *arg)
{
	t_philo_data	*data;
	int				i;

	data = (t_philo_data *)arg;
	while (1)
	{
		i = -1;
		while (++i < data->nbr_philo)
		{
			if (condition_die(&data->philo_man[i]))
				break ;
		}
		if (data->philo_man[data->nbr_philo - 1].add_eat == data->nbr_eat)
			break ;
		if (data->one_dead)
			break ;
	}
	return (NULL);
}

bool	print_time(char *str, t_philosophe *thinkeur)
{
	long	time;

	time = actual_time();
	if (time == -1)
		return (false);
	time = time - thinkeur->data->start_time;
	printf("%ld %d %s\n", time, thinkeur->id, str);
	if (slib_cmp(str, "is eating"))
		thinkeur->last_meal = time;
	return (true);
}
