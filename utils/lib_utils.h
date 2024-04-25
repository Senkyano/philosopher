/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:20:28 by rihoy             #+#    #+#             */
/*   Updated: 2024/04/25 14:33:02 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_UTILS_H
# define LIB_UTILS_H

# include <stddef.h>
# include <stdbool.h>

// COLORS
# define BLK "\e[0;90m"
# define RED "\e[1;31m"
# define GR "\e[1;92m"
# define Y "\e[1;93m"
# define BLU "\e[1;94m"
# define PUR "\e[1;95m"
# define CY "\e[1;96m"
# define WH "\e[0;97m"
# define RST "\e[0m"
# define ERR_MAL "-- Malloc failed --\n"

typedef struct s_data_lib
{
	char	*new_str;
	int		i;
	int		x;
	int		j;
	int		trig;
}	t_data_lib;

typedef struct s_data_atoi
{
	long int		nbr;
	int				negatif;
	bool			error;
} t_data_atoi;

// Nbr
t_data_atoi	lib_atoi(char *str);
int			nbr_base(long int nbr, int base);
// FD
int			write_str_fd(char *str, int fd);
int			write_fd(char c, int fd);
// IS
bool		is_space(char c);
bool		is_num(char c);
bool		is_char(char c);
// CHECK
bool		str_good(char *str);
// PRINT
void		print_char(char c, int fd);
size_t		print_c(char c);
void		print_str(char *str);
int			print_error(char *str);
void		print_sent(char **str);
int			printf_error(const char *str, ...);
// LEN
int			str_len(char *str);
size_t		sent_len(char **sent);
// CMP
bool		str_cmp(char *str, char *str2);
bool		slib_cmp(char *str, char *str2);
bool		last_cmp(char *str, char *str2);
bool		str_ncmp(char *str, char *str2, size_t n);
// JOIN
char		*str_join(char *str1, char *str2);
char		*str2_join(char *str1, char *str2);
char		*strall_join(char *str1, char *str2);
char		*opti1_join(char *str1, char *str2);
// DUP
char		*lib_strdup(char *str);
char		*lib_strup(char *str);
char		*strup_to(char *str, int n);
//		SENT
char		**copy_sent(char **sent);
char		**sentup(char *str);
char		**sentup_n(char **sent, char *str, size_t n);
// SPLIT
char		**lib_split(char *str, char *set);
// FREE
void		lib_free_split(char **sent);
// SRCH
int			lib_srch(char *str, char to_find);
// set
void		*lib_memset(void *pt, int value, size_t stats);

#endif