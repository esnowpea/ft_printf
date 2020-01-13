/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:01:45 by esnowpea          #+#    #+#             */
/*   Updated: 2020/01/13 17:10:50 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
t_type g_type[] = {
		{'c', &ft_c}
		{'s', &ft_s}
		{'p', &ft_p}
		{'d', &ft_d}
		{'o', &ft_o}
		{'u', &ft_u}
		{'x', &ft_x}
		{'X', &ft_X}
		{'f', &ft_f}
		{'e', &ft_e}
		{'g', &ft_g}
};*/

unsigned int x2(unsigned int k)
{
	unsigned int out;
	unsigned int l;

	out = 0;
	l = 1 << 31;
	while (!(k & l) && l)
	{
		l = l >> 1;
	}
	//if (l == 0)
	//write(1, "0", 1);
	while (l)
	{
		if (k & l)
			out = out * 10 + 1;//write(1, "1", 1);
		else
			out = out * 10 + 0;//write(1, "0", 1);
		l = l >> 1;
	}
	return (out);
}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	t_format_sp spec;

	va_start(ap, format);
	while (*format)
	{
		if (*format == '%' && *(++format) != '%')
		{
			spec = parsing(&format, ap);

		}
		else
			ft_putchar(*format);
		format++;
	}
	va_end(ap);
	return (0); //char count
}