/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 22:34:16 by rihoy             #+#    #+#             */
/*   Updated: 2024/05/15 17:59:11 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->data->die);
	if (philo->data->one_dead)
		return (pthread_mutex_unlock(&philo->data->die), NULL);
	pthread_mutex_unlock(&philo->data->die);
	while (1)
	{
		break ;
	}
	return (NULL);
}
