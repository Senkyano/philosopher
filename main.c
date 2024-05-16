/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:22:20 by rihoy             #+#    #+#             */
/*   Updated: 2024/05/16 15:07:10 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	init_sec(t_table *table, int argc);
bool	init_table(t_table *table, char **argv);
bool	launch_philo(t_table *table);

int	main(int argc, char **argv)
{
	t_table		table;

	if (argc < 5 || argc > 6)
	{
		printf(RED"Error: wrong number of arguments\n"RST);
		return (1);
	}
	if (!init_table(&table, argv))
		return (1);
	if (!init_sec(&table, argc))
		return (1);
	printf(GR"Simulation started\n"RST);
	if (!launch_philo(&table))
		return (1);
	wait_threads(&table);
	printf(GR"Simulation ended\n"RST);
	return (0);
}

bool	launch_philo(t_table *table)
{
	int	i;

	i = -1;
	if (pthread_create(&table->admin_thread, NULL, admin, table) != 0)
	{
		table->one_dead = true;
		return (printf(RED"Error: pthread_create failed\n"RST), false);
	}
	while (++i < table->nbr_philo)
	{
		if (pthread_create(&table->man[i].philo_thread, NULL, \
		philo_routine, &table->man[i]) != 0)
		{
			table->one_dead = true;
			return (printf(RED"Error: pthread_create failed\n"RST), false);
		}
	}
	table->all_create = true;
	return (true);
}

bool	init_table(t_table *table, char **argv)
{
	t_data_atoi	info_atoi;
	int			i;

	memset(table, 0, sizeof(t_table));
	i = 0;
	while (argv[++i])
	{
		info_atoi = lib_atoi(argv[i]);
		if (info_atoi.error == true)
			return (printf(RED"Error: invalid argument\n"RST), false);
		if (i == 1)
			table->nbr_philo = info_atoi.nbr;
		else if (i == 2)
			table->time_to_die = info_atoi.nbr;
		else if (i == 3)
			table->time_to_eat = info_atoi.nbr;
		else if (i == 4)
			table->time_to_sleep = info_atoi.nbr;
		else if (i == 5)
			table->tot_eat = info_atoi.nbr;
	}
	if (table->nbr_philo <= 0 || table->time_to_die <= 0 || \
	table->time_to_eat <= 0 || table->time_to_sleep <= 0 || table->tot_eat < 0)
		return (printf(RED"Error: invalid argument\n"RST), false);
	return (true);
}

bool	init_sec(t_table *table, int argc)
{
	int	i;

	i = -1;
	if (argc == 5 && table->tot_eat == 0)
		table->tot_eat = -1;
	table->man = malloc(sizeof(t_philo) * table->nbr_philo);
	if (table->man == NULL)
		return (printf(RED"Error: malloc failed\n"RST), false);
	while (++i < table->nbr_philo)
	{
		if (!init_philo(i, table, &table->man[i]))
			return (free_all_philo(i - 1, table), false);
	}
	if (pthread_mutex_init(&table->die, NULL) != 0)
	{
		printf(RED"Error: mutex init failed\n"RST);
		return (free_all_philo(i - 1, table), false);
	}
	if (pthread_mutex_init(&table->write, NULL) != 0)
	{
		printf(RED"Error: mutex init failed\n"RST);
		pthread_mutex_destroy(&table->die);
		return (free_all_philo(i - 1, table), false);
	}
	return (true);
}

long	actual_time(void)
{
	struct timeval	tv;
	time_t			secondes;
	suseconds_t		microsecondes;
	long			time;

	if (gettimeofday(&tv, NULL) == -1)
		return (printf(RED"Error: gettimeofday failed\n"RST), -1);
	secondes = tv.tv_sec;
	microsecondes = tv.tv_usec;
	time = secondes * 1000 + microsecondes / 1000;
	return (time);
}
