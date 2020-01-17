/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 11:59:57 by esnowpea          #+#    #+#             */
/*   Updated: 2020/01/17 16:46:37 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_c(t_format_sp spec, va_list ap)
{
	char	c;
	char 	*str;
	char 	*s;
	int 	len;

	c = '%';
	if (spec.type != '%')
		c = va_arg(ap, int);
	str = ft_strnew(2);
	*str = c;
	s = handler_flags(str, spec);
	len = (int)ft_strlen(s);
	write(1, s, len);
	free(s);
	return (len);
}
