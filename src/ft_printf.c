/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:01:45 by esnowpea          #+#    #+#             */
/*   Updated: 2020/01/24 17:03:51 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_type g_type[] = {
		{'c', &ft_c},
		{'%', &ft_c},
		{'s', &ft_s},
		{'d', &ft_d},
		{'i', &ft_d},
		{'p', &ft_d},
		{'o', &ft_d},
		{'u', &ft_d},
		{'x', &ft_d},
		{'X', &ft_d},
		{'b', &ft_d},
		{'f', &ft_f}/*,
		{'e', &ft_e},
		{'g', &ft_g}*/
};
int g_len;

t_str_len	find_function(t_format_sp spec, va_list ap)
{
	int			i;
	t_str_len	s;

	i = 0;
	s.str = 0;
	s.len = 0;
	while (i < (int)(sizeof(g_type) / sizeof(t_type)))
	{
		if (g_type[i].type == spec.type)
			return (g_type[i].func(spec, ap));
		i++;
	}
	return (s);
}

char		*ft_strfill(char c, int length)
{
	char	*str;
	int		i;

	str = (char*)malloc(sizeof(char) * (length + 1));
	if (!str)
		return (0);
	i = 0;
	while (i < length)
		str[i++] = c;
	str[i] = '\0';
	return (str);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*ptr;
	int			len;
	t_str_len	s;

	va_start(ap, format);
	g_len = 0;
	while ((ptr = ft_strchr(format, '%')))
	{
		len = (int)ft_strlen(format) - (int)ft_strlen(ptr);
		write(FD, format, len);
		g_len += len;
		format = ptr + 1;
		s = find_function(parsing(&format, ap), ap);
		format += *format ? 1 : 0;
		write(FD, s.str, s.len);
		g_len += s.len;
		free(s.str);
	}
	write(FD, format, (int)ft_strlen(format));
	g_len += (int)ft_strlen(format);
	va_end(ap);
	return (g_len);
}
