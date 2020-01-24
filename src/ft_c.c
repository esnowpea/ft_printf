/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 11:59:57 by esnowpea          #+#    #+#             */
/*   Updated: 2020/01/24 16:49:45 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_str_len	ft_c(t_format_sp spec, va_list ap)
{
	char		c;
	char		*str;

	c = '%';
	if (spec.type != '%')
		c = va_arg(ap, int);
	str = ft_strnew(2);
	*str = c;
	return (handler_flags(str, spec));
}
