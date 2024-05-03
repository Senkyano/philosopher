/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:22:20 by rihoy             #+#    #+#             */
/*   Updated: 2024/05/03 12:44:35 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	init_table(char **argv, t_philo_data *philo);
bool	check_philo(int argc);

int	main(int argc, char **argv)
{
	t_philo_data	philo;

	if (!check_philo(argc))
		exit(1);
	lib_memset(&philo, 0, sizeof(t_philo_data));
	if (!init_table(argv, &philo))
		exit(1);
	// creation des philosophe
	// boucle check de vie des philosophe
	return (0);
}

bool	check_philo(int argc)
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
