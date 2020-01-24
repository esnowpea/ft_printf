/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 11:59:57 by esnowpea          #+#    #+#             */
/*   Updated: 2020/01/24 14:46:07 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_c(t_format_sp spec, va_list ap)
{
	char		c;
	char		*str;
	t_str_len	s;

	c = '%';
	if (spec.type != '%')
		c = va_arg(ap, int);
	str = ft_strnew(2);
	*str = c;
	s = handler_flags(str, spec);
	write(1, s.str, s.len);
	free(s.str);
	return (s.len);
}
