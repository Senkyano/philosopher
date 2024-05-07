/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liberation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:52:58 by rihoy             #+#    #+#             */
/*   Updated: 2024/05/07 18:29:05 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	free_philosophe(t_philo_data *table)
{
	int	i;

	i = -1;
	while (++i < table->nbr_philo)
	{
		pthread_mutex_destroy(&table->philo_man[i].left_fork);
		if (table->philo_man[i].philo_thread)
			pthread_join(table->philo_man[i].philo_thread, NULL);
	}
	free(table->philo_man);
	pthread_mutex_destroy(&table->die);
	if (table->admin_thread)
		pthread_join(table->admin_thread, NULL);
}
