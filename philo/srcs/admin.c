/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   admin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 20:10:53 by rihoy             #+#    #+#             */
/*   Updated: 2024/05/21 17:10:57 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	check_death_admin(t_table *data);

void	*admin(void *arg)
{
	t_table	*data;

	data = (t_table *)arg;
	pthread_mutex_lock(&data->create);
	data->start_time = actual_time();
	if (data->start_time == -1)
	{
		data->one_dead = true;
		return (pthread_mutex_unlock(&data->create), NULL);
	}
	data->admin_ready = true;
	pthread_mutex_unlock(&data->create);
	while (1)
	{
		if (check_death_admin(data))
			return (NULL);
		if (data->man[data->nbr_philo - 1].nbr_eat == data->tot_eat)
			return (NULL);
	}
	return (NULL);
}

int	check_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->die);
	if (philo->data->one_dead)
		return (pthread_mutex_unlock(&philo->data->die), true);
	pthread_mutex_unlock(&philo->data->die);
	return (false);
}

int	check_death_admin(t_table *data)
{
	int		i;
	long	time;

	i = -1;
	time = actual_time();
	if (time == -1)
	{
		data->one_dead = true;
		return (true);
	}
	time = time - data->start_time;
	while (++i < data->nbr_philo)
	{
		if (time - data->man[i].last_meal >= data->time_to_die)
		{
			pthread_mutex_lock(&data->die);
			pthread_mutex_lock(&data->write);
			data->one_dead = true;
			printf(RED"%ld %d died\n"RST, time, i);
			pthread_mutex_unlock(&data->write);
			return (pthread_mutex_unlock(&data->die), true);
		}
	}
	return (false);
}
