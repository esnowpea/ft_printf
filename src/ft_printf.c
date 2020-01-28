/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:01:45 by esnowpea          #+#    #+#             */
/*   Updated: 2020/01/28 17:44:13 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_str_len	find_function(t_format_sp spec, va_list ap)
{
	int			i;
	t_str_len	s;
	t_type		type[] = SPEC_FUN;

	i = 0;
	while (i < (int)(sizeof(type) / sizeof(t_type)))
	{
		if (type[i].type == spec.type)
			return (type[i].func(spec, ap));
		i++;
	}
	s.len = 0;
	s.str = ft_strnew(s.len);
	return (s);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*ptr;
	int			len_out;
	t_str_len	s;

	va_start(ap, format);
	len_out = 0;
	while ((ptr = ft_strchr(format, '%')))
	{
		write(FD, format, (int)ft_strlen(format) - (int)ft_strlen(ptr));
		len_out += (int)ft_strlen(format) - (int)ft_strlen(ptr);
		format = ptr + 1;
		s = find_function(parsing(&format, ap), ap);
		if (s.str == NULL && s.len == 0)
			exit(EXIT_FAILURE);
		format += *format ? 1 : 0;
		write(FD, s.str, s.len);
		len_out += s.len;
		free(s.str);
	}
	write(FD, format, (int)ft_strlen(format));
	len_out += (int)ft_strlen(format);
	va_end(ap);
	return (len_out);
}
