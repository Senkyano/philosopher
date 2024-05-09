/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:22:20 by rihoy             #+#    #+#             */
/*   Updated: 2024/05/09 15:48:11 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	init_table(char **argv, t_philo_data *philo);
bool	check_philo(int argc);
bool	init_all(t_philo_data *table);

int	main(int argc, char **argv)
{
	t_philo_data	philo;
	int				philo_id;
	int				i;

	i = -1;
	if (!check_philo(argc))
		exit(1);
	lib_memset(&philo, 0, sizeof(t_philo_data));
	if (!init_table(argv, &philo))
		exit(1);
	if (!init_all(&philo))
		exit(1);
	philo.start_time = actual_time();
	while (++i < philo.nbr_philo)
	{
		philo_id = pthread_create(&philo.philo_man[i].philo_thread, NULL, routine_philo, &philo.philo_man[i]);
		if (philo_id != 0)
		{
			printf_error(RED"Error: pthread_create failed\n"RST);
			exit(1);
		}
	}
	free_philosophe(&philo);
	return (0);
}

bool	check_philo(int argc)
{
	if (argc < 5)
	{
		printf_error(RED"Error: not enough arguments\n"RST);
		return (false);
	}
	else if (argc > 6)
	{
		printf_error(RED"Error: too many arguments\n"RST);
		return (false);
	}
	return (true);
}

bool	init_all(t_philo_data *table)
{
	table->admin_thread = 0;
	if (table->nbr_eat == 0)
		table->nbr_eat = -1;
	if (!init_philo(table))
		return (false);
	return (true);
}

bool	init_table(char **argv, t_philo_data *philo)
{
	int			index;
	t_data_atoi	info_atoi;

	index = 0;
	lib_memset(&info_atoi, 0, sizeof(t_data_atoi));
	while (argv[++index])
	{
		info_atoi = lib_atoi(argv[index]);
		if (info_atoi.error || argv[index][0] == '-' || info_atoi.nbr < 0)
		{
			printf_error(RED"Error: invalid argument\n"RST);
			return (false);
		}
		if (index == 1)
			philo->nbr_philo = info_atoi.nbr;
		else if (index == 2)
			philo->time_to_die = info_atoi.nbr;
		else if (index == 3)
			philo->time_to_eat = info_atoi.nbr;
		else if (index == 4)
			philo->time_to_sleep = info_atoi.nbr;
		else if (index == 5)
			philo->nbr_eat = info_atoi.nbr;
	}
	return (true);
}
