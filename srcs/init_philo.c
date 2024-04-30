/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:18:21 by rihoy             #+#    #+#             */
/*   Updated: 2024/04/30 14:26:41 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	init_philo(t_philo_data *info_table)
{
	int	id;

	id = -1;
	info_table->philo = malloc(sizeof(t_philosophe) * info_table->nbr_philo);
	if (!info_table->philo)
	{
		printf_error(RED"Error: malloc failed\n");
		return (false);
	}
	while (++id < info_table->nbr_philo)
	{
		info_table->philo[id].id = id;
		info_table->philo[id].time = 0;
		info_table->philo[id].last_meal = 0;
	}
}
