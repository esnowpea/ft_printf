/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:37:18 by esnowpea          #+#    #+#             */
/*   Updated: 2020/01/16 15:18:42 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_d(t_format_sp spec, va_list ap)
{
	/*long long int	d;
	char 				*str;

	d.lld = va_arg(ap, long long int);
	if (spec.size & (1 << 0))
	{
		d.ld = va_arg(ap, long int);
		str = ft_itoa(d.ld);
	}
	else if (spec.size & (1 << 1))
		d.lld = va_arg(ap, long long int);
	else if (spec.size & (1 << 2))
		d.hd = (short int)va_arg(ap, int);
	else if (spec.size & (1 << 3))
		d.hhd = (signed char)va_arg(ap, int);
	else
		d.d = va_arg(ap, int);*/
/*	long long int	d;
	char 			*str;
	int 			len;

	d = va_arg(ap, long long int);
	if (!(str = ft_itoa(d)))
		return (-1);
	len = 0;
	if (!(str = ft_strfill(' ', len)))
		return (-1);
	if ((spec.flags & 1) == 1)
		str = add_s_left(str, s, len_s);
	else
		str = add_s_right(str, s, len_s);*/
}