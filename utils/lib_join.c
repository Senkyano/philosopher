/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:29:02 by rihoy             #+#    #+#             */
/*   Updated: 2024/04/21 14:47:06 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_utils.h"
#include <stdlib.h>
#include <unistd.h>

/* Concaténe 2 chaine de caracterès pour en produire une nouvelle sans free */

char	*str_join(char *str1, char *str2)
{
	size_t	i;
	size_t	j;
	char	*new_str;

	new_str = malloc((str_len(str1) + str_len(str2) + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = -1;
	j = -1;
	while (str1[++i])
		new_str[i] = str1[i];
	while (str2[++j])
		new_str[i++] = str2[j];
	new_str[i] = '\0';
	return (new_str);
}

/* Concaténe 2 chaine de caracterès pour en produire une nouvelle et free str1 */

char	*opti1_join(char *str1, char *str2)
{
	t_data_lib	data;

	lib_memset(&data, 0, sizeof(data));
	data.x = -1;
	data.i = -1;
	if (!str1)
	{
		str1 = lib_strup("");
		if (!str1)
			return (NULL);
	}
	if (!str2)
		return (str1);
	data.new_str = malloc((str_len(str1) + str_len(str2) + 1) * sizeof(char));
	if (!data.new_str)
		return (NULL);
	while (str1[++data.i])
		data.new_str[data.i] = str1[data.i];
	while (str2[++data.x])
		data.new_str[data.i++] = str2[data.x];
	data.new_str[data.i] = '\0';
	free(str1);
	return (data.new_str);
}

/* Concaténe 2 chaine de caracterès pour en produire une nouvelle et free str2 */

char	*str2_join(char *str1, char *str2)
{
	size_t	i;
	size_t	j;
	char	*new_str;

	new_str = malloc((str_len(str1) + str_len(str2) + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = -1;
	j = -1;
	while (str1[++i])
		new_str[i] = str1[i];
	while (str2[++j])
		new_str[i + j] = str2[j];
	new_str[i + j] = '\0';
	free(str2);
	return (new_str);
}

/* Concaténe 2 chaine de caracterès pour en produire une nouvelle et free str1 */
/* et str2                                                                     */

char	*strall_join(char *str1, char *str2)
{
	t_data_lib	data;

	lib_memset(&data, -1, sizeof(data));
	if (!str1)
	{
		str1 = lib_strup("");
		if (!str1)
			return (NULL);
	}
	if (!str2)
	{
		str2 = lib_strup("");
		if (!str2)
			return (free(str1), NULL);
	}
	data.new_str = malloc((str_len(str1) + str_len(str2) + 1) * sizeof(char));
	if (!data.new_str)
		return (NULL);
	while (str1[++data.i] != 0)
		data.new_str[data.i] = str1[data.i];
	while (str2[++data.j] != 0)
		data.new_str[data.i + data.j] = str2[data.j];
	data.new_str[data.i + data.j] = '\0';
	return (free(str2), free(str1), data.new_str);
}
