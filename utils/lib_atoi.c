/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:35:53 by rihoy             #+#    #+#             */
/*   Updated: 2024/04/25 19:16:36 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_utils.h"

t_data_atoi	lib_atoi(char *str)
{
	t_data_atoi	lib_atoi;
	int			index;
	
	lib_memset(&lib_atoi, 0, sizeof(t_data_atoi));
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
