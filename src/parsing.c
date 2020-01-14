/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 17:16:35 by esnowpea          #+#    #+#             */
/*   Updated: 2020/01/14 16:24:10 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format_sp parsing3(const char **format, t_format_sp spec)
{
	if (**(format) == 'l' && *(*(format) + 1) != 'l')
		spec.size |= 1 << 0;
	else if (**(format) == 'l' && *(*(format) + 1) == 'l')
		spec.size |= 1 << 1;
	else if (**(format) == 'h' && *(*(format) + 1) != 'h')
		spec.size |= 1 << 2;
	else if (**(format) == 'h' && *(*(format) + 1) == 'h')
		spec.size |= 1 << 3;
	else if (**(format) == 'L')
		spec.size |= 1 << 4;
	if (**(format) == 'l' || **(format) == 'h' || **(format) == 'L')
		(*format)++;
	if (**(format) == 'l' || **(format) == 'h')
		(*format)++;
	spec.type = **(format);
	return (spec);
}

/*  define width and accuracy */

t_format_sp parsing2(const char **format, va_list ap, t_format_sp spec)
{
	if (**(format) <= '9' && **(format) >= '0')
		spec.width = ft_atoi(*format);
	else if (**(format) == '*')
		spec.width = va_arg(ap, int);
	while ((**(format) <= '9' && **(format) >= '0') || **(format) == '*')
		(*format)++;
	if (**(format) == '.')
	{
		(*format)++;
		if (**(format) <= '9' && **(format) >= '0')
			spec.accur = ft_atoi(*format);
		else if (**(format) == '*')
			spec.accur = va_arg(ap, int);
	}
	while ((**(format) <= '9' && **(format) >= '0') || **(format) == '*')
		(*format)++;
	return (parsing3(format, spec));
}

/*  define flags   */

t_format_sp parsing(const char **format, va_list ap)
{
	t_format_sp spec;
	spec.flags = 0;
	spec.size = 0;
	spec.width = -1;
	spec.accur = -1;
	while (**(format) == '-' || *(*(format)) == '+' || *(*(format)) == ' ' || \
	*(*(format)) == '#' || *(*(format)) == '0')
	{
		if (**(format) == '-')
			spec.flags |= 1 << 0;
		else if (**(format) == '+')
			spec.flags |= 1 << 1;
		else if (**(format) == ' ')
			spec.flags |= 1 << 2;
		else if (**(format) == '#')
			spec.flags |= 1 << 3;
		else if (**(format) == '0')
			spec.flags |= 1 << 4;
		(*format)++;
	}
	return (parsing2(format, ap, spec));
}