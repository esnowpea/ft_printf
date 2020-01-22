/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgriseld <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:46:22 by dgriseld          #+#    #+#             */
/*   Updated: 2020/01/22 20:10:54 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	ft_d_size_unsig(t_format_sp spec, va_list ap)
{
	if (spec.size & 1)
		return ((unsigned long long)va_arg(ap, unsigned long));
	else if (spec.size & 2)
		return ((unsigned long long)va_arg(ap, unsigned long long));
	else if (spec.size & 4)
		return ((unsigned long long)((unsigned short)va_arg(ap, unsigned int)));
	else if (spec.size & 8)
		return ((unsigned long long)((unsigned char)va_arg(ap, unsigned int)));
	else
		return ((unsigned long long)va_arg(ap, unsigned int));
}

int						ft_x(t_format_sp spec, va_list ap)
{
	int 				len;
	unsigned long long	p;
	char 				*s;

	if (!(p = ft_d_size_unsig(spec, ap)))
		return (-1);
	s = print_base_nbr(p, 0, spec);
	s = handler_flags(s, spec);
	len = (int)ft_strlen(s);
	write(1, s, len);
	free(s);
	return (len);
}
