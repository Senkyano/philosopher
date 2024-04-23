/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:22:20 by rihoy             #+#    #+#             */
/*   Updated: 2024/04/23 15:21:09 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	init_philo(int argc, char **argv, t_philo *philo);
bool	check_philo(int argc, char **argv);

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (!check_philo(argc, argv))
		exit(0);
	lib_memset(&philo, 0, sizeof(t_philo));
	if (!init_philo(argc, argv, &philo))
		exit(0);
}

bool	check_philo(int argc, char **argv)
{
	if (argc < 5)
	{
		printf_error(RED"Error: not enough arguments\n");
		return (false);
	}
	else if (argc > 6)
	{
		printf_error(RED"Error: too many arguments\n");
		return (false);
	}
}

bool	init_philo(int argc, char **argv, t_philo *philo)
{
	int			index;
	t_data_atoi	info_atoi;
	
	index = 0;
	while (argv[++index])
	{
		info_atoi = lib_atoi(argv[index]);
		if (info_atoi.error)
		{
			printf_error(RED"Error: invalid argument\n");
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
