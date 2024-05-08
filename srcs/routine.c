/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 22:34:16 by rihoy             #+#    #+#             */
/*   Updated: 2024/05/08 11:31:30 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*routine_philo(void *philo)
{
	t_philosophe	*philo_man;

	printf_error("philo is\n");
	philo_man = (t_philosophe *)philo;
	(void)philo_man;
	while (1)
	{
		printf_error("philo is\n");
		usleep(1000);
	}
	return (NULL);
}

void	start_philo(t_philosophe *philo)
{
	if (philo->id % 2 == 0)
	{
	}
	else
	{
	}
}

void	*admin_philo(void *data_info)
{
	// int				i;
	t_philo_data	*data;

	data = (t_philo_data *)data_info;
	(void)data;
	printf_error("admin is\n");
	return (NULL);
}
