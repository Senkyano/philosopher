/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   admin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 20:10:53 by rihoy             #+#    #+#             */
/*   Updated: 2024/05/15 17:58:11 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*admin(void *arg)
{
	t_table	*data;

	data = (t_table *)arg;
	pthread_mutex_lock(&data->die);
	printf("admin\n");
	if (data->one_dead)
		return (pthread_mutex_unlock(&data->die), NULL);
	pthread_mutex_unlock(&data->die);
	while (1)
	{
		break ;
	}
	return (NULL);
}
