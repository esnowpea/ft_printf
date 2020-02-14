/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 17:16:35 by esnowpea          #+#    #+#             */
/*   Updated: 2020/02/14 16:19:12 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			type_to_base(char type)
{
	if (type == 'd' || type == 'i' || type == 'u')
		return (10);
	else if (type == 'b')
		return (2);
	else if (type == 'p' || type == 'x' || type == 'X')
		return (16);
	else if (type == 'o')
		return (8);
	else
		return (0);
}

char		*find_spec(const char *format)
{
	if (ft_strchr(format, 'c') || ft_strchr(format, 's')
	|| ft_strchr(format, 'p') || ft_strchr(format, 'd')
	|| ft_strchr(format, 'o') || ft_strchr(format, 'u')
	|| ft_strchr(format, 'x') || ft_strchr(format, 'X')
	|| ft_strchr(format, 'f') || ft_strchr(format, 'e')
	|| ft_strchr(format, 'g') || ft_strchr(format, '%')
	|| ft_strchr(format, 'i') || ft_strchr(format, 'b')
	|| ft_strchr(format, 'E') || ft_strchr(format, 'G'))
		return (0);
	return ("1");
}

t_format_sp	parsing3(const char **format, t_format_sp spec)
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
	while (**(format) != 'c' && **(format) != 's' && **(format) != 'p' && \
	**(format) != 'd' && **(format) != 'o' && **(format) != 'u' && \
	**(format) != 'x' && **(format) != 'X' && **(format) != 'f' && \
	**(format) != 'e' && **(format) != 'g' && **(format) != '%' && \
	**(format) != 'i' && **(format) != 'b' && **(format) != '\0' && \
	**(format) != 'E' && **(format) != 'G')
		(*format)++;
	spec.type = **(format);
	*format += **format ? 1 : 0;
	spec.base = type_to_base(spec.type);
	return (spec);
}

/*
** define width and accuracy
*/

t_format_sp	parsing2(const char **format, va_list ap, t_format_sp spec)
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
		if (**(format) == '*')
			spec.accur = va_arg(ap, int);
		else
			spec.accur = ft_atoi(*format);
	}
	while ((**(format) <= '9' && **(format) >= '0') || **(format) == '*')
		(*format)++;
	return (parsing3(format, spec));
}

/*
** define flags
*/

t_format_sp	parsing(const char **format, va_list ap)
{
	t_format_sp spec;

	spec.flags = 0;
	spec.size = 0;
	spec.width = 0;
	ft_memcpy(spec.sign, "\0\0\0", 3);
	spec.accur = -1;
	if (find_spec(*format))
		return (spec);
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
