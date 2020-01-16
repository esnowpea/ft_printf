/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:01:35 by esnowpea          #+#    #+#             */
/*   Updated: 2020/01/14 13:04:18 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FT_PRINTF_H
#define FT_PRINTF_FT_PRINTF_H

# include <zconf.h>
# include <libft.h>

# define max(a, b) a > b ? a : b
# define min(a, b) a < b ? a : b

typedef struct		s_format_sp
{
	unsigned short 	flags;
	int				width;
	int 			accur;
	unsigned short 	size;
	char			type;
}					t_format_sp;

typedef struct		s_type
{
	char 			type;
	int				(*func)(t_format_sp spec, va_list ap);
}					t_type;

/*
**	FLAGS:
**	'-'	- 00001
**	'+'	- 00010
**	' '	- 00100
**	'#'	- 01000
**	'0'	- 10000
**
**	SIZE:
**	'l'	- 00001
**	'll'- 00010
**	'h'	- 00100
**	'hh'- 01000
**	'L'	- 10000
*/

int			ft_printf(const char *format, ...);
t_format_sp	parsing(const char **format, va_list ap);
char 		*ft_strfill(char c, int length);
int			ft_c(t_format_sp spec, va_list ap);
int			ft_s(t_format_sp spec, va_list ap);

#endif //FT_PRINTF_FT_PRINTF_H


