/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liberation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:52:58 by rihoy             #+#    #+#             */
/*   Updated: 2024/05/15 17:09:15 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	wait_threads(t_table *data)
{
	int	i;

	i = -1;
	while (++i < data->nbr_philo)
	{
		if (data->man[i].philo_thread)
			pthread_join(data->man[i].philo_thread, NULL);
	}
	pthread_join(data->admin_thread, NULL);
	free_all_philo(data->nbr_philo - 1, data);
	pthread_mutex_destroy(&data->die);
}
