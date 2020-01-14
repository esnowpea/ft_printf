/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:01:45 by esnowpea          #+#    #+#             */
/*   Updated: 2020/01/14 11:51:43 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_type g_type[] = {
		{'c', &ft_c}/*
		{'s', &ft_s}
		{'p', &ft_p}
		{'d', &ft_d}
		{'o', &ft_o}
		{'u', &ft_u}
		{'x', &ft_x}
		{'X', &ft_X}
		{'f', &ft_f}
		{'e', &ft_e}
		{'g', &ft_g}*/
};

void 	find_function(t_format_sp spec, va_list ap)
{
	int		i;

	i = 0;
	while (i < sizeof(g_type) / sizeof(t_type))
	{
		 if (g_type[i].type == spec.type)
		 {
			  g_type[i].func(spec, ap);
			  return ;
		 }
		 i++;
	}
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;

	va_start(ap, format);
	while (*format)
	{
		if (*format == '%' && *(++format) != '%')
		{
			find_function(parsing(&format, ap), ap);
		}
		else
			ft_putchar(*format);
		format++;
	}
	va_end(ap);
	return (0); //TODO: char count
}