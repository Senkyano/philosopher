/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:18:21 by rihoy             #+#    #+#             */
/*   Updated: 2024/05/15 12:22:44 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	init_man(t_philosophe *philo, int id);
void	close_mutex(t_philo_data *if_tb, int n);

bool	init_philo(t_philo_data *if_tb)
{
	int	id;

	id = -1;
	if_tb->philo_man = malloc(sizeof(t_philosophe) * if_tb->nbr_philo);
	if (!if_tb->philo_man)
	{
		printf_error(RED"Error: malloc failed\n"RST);
		return (false);
	}
	while (++id < if_tb->nbr_philo)
	{
		if_tb->philo_man[id].data = if_tb;
		if (!init_man(&if_tb->philo_man[id], id))
		{
			close_mutex(if_tb, id);
			return (false);
		}
		if (if_tb->nbr_philo != 1 && id == if_tb->nbr_philo - 1)
			if_tb->philo_man[id].right_fork = &if_tb->philo_man[0].left_fork;
		else if (if_tb->nbr_philo != 1)
			if_tb->philo_man[id].right_fork = \
		&if_tb->philo_man[id + 1].left_fork;
	}
	return (true);
}

bool	init_man(t_philosophe *philo, int id)
{
	philo->id = id;
	philo->add_eat = 0;
	philo->last_meal = 0;
	philo->philo_thread = 0;
	philo->right_fork = NULL;
	if (pthread_mutex_init(&philo->left_fork, NULL))
	{
		printf_error(RED"Error: mutex init failed\n"RST);
		return (false);
	}
	return (true);
}

void	close_mutex(t_philo_data *if_tb, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		pthread_mutex_destroy(&if_tb->philo_man[i].left_fork);
	free(if_tb->philo_man);
}
