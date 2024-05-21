/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liberation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:52:58 by rihoy             #+#    #+#             */
/*   Updated: 2024/05/21 02:36:12 by rihoy            ###   ########.fr       */
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
	pthread_mutex_destroy(&data->die);
	free_all_philo(data->nbr_philo - 1, data);
}

t_data_atoi	lib_atoi(char *str)
{
	t_data_atoi	lib_atoi;
	int			index;

	memset(&lib_atoi, 0, sizeof(t_data_atoi));
	index = -1;
	if (str[0] == '-')
	{
		lib_atoi.negatif = -1;
		index++;
	}
	else
		lib_atoi.negatif = 1;
	while (str[++index])
	{
		if (str[index] < '0' || str[index] > '9')
			lib_atoi.error = true;
		lib_atoi.nbr = lib_atoi.nbr * 10 + str[index] - '0';
		if (lib_atoi.nbr > 2147483647 && lib_atoi.negatif == 1)
			lib_atoi.error = true;
		else if (lib_atoi.nbr > 2147483648 && lib_atoi.negatif == -1)
			lib_atoi.error = true;
	}
	lib_atoi.nbr *= lib_atoi.negatif;
	return (lib_atoi);
}

void	all_destroy(t_table *data)
{
	pthread_mutex_destroy(&data->die);
	pthread_mutex_destroy(&data->write);
	pthread_mutex_unlock(&data->create);
	pthread_mutex_destroy(&data->create);
}

bool	create_mutex(t_table *data)
{
	if (pthread_mutex_init(&data->die, NULL) != 0)
	{
		printf(RED"Error: mutex init failed\n"RST);
		return (free_all_philo(data->nbr_philo - 1, data), false);
	}
	if (pthread_mutex_init(&data->write, NULL) != 0)
	{
		printf(RED"Error: mutex init failed\n"RST);
		pthread_mutex_destroy(&data->die);
		return (free_all_philo(data->nbr_philo - 1, data), false);
	}
	if (pthread_mutex_init(&data->create, NULL) != 0)
	{
		printf(RED"Error: mutex init failed\n"RST);
		pthread_mutex_destroy(&data->die);
		pthread_mutex_destroy(&data->write);
		return (free_all_philo(data->nbr_philo - 1, data), false);
	}
	return (true);
}
