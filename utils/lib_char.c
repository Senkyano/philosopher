/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:15:35 by rihoy             #+#    #+#             */
/*   Updated: 2024/04/21 14:49:09 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_utils.h"
#include <unistd.h>
#include <stddef.h>

size_t	print_c(char c)
{
	write(1, &c, 1);
	return (1);
}

void	print_str(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		print_c(str[i++]);
}

void	print_sent(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		print_str(str[i]);
		print_str("\n");
		i++;
	}
}
