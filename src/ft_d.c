/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:37:18 by esnowpea          #+#    #+#             */
/*   Updated: 2020/01/22 20:10:54 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char 	*ft_d_size(t_format_sp spec, va_list ap, int base)
{
	if (spec.size & 1)
		return (ft_itoa_base_long((long long)va_arg(ap, long) , base));
	else if (spec.size & 2)
		return (ft_itoa_base_long(va_arg(ap, long long), base));
	else if (spec.size & 4)
		return (ft_itoa_base_long((long long)((short)va_arg(ap, int)), base));
	else if (spec.size & 8)
		return (ft_itoa_base_long((long long)((char)va_arg(ap, int)), base));
	else
		return (ft_itoa_base_long((long long)va_arg(ap, int), base));
}

int		ft_d(t_format_sp spec, va_list ap)
{
	char 	*str;
	char 	*s;
	int 	len;
	int 	len_s;
	int 	sign;

	if (!(str = ft_d_size(spec, ap, spec.base)))
		return (-1);
	if (*str == '0' && spec.accur == 0)
	{
		free(str);
		if (!(str = ft_strfill(' ', 0)))
			return (0);
	}
	if (*str == '-')
		spec.sign = '-';
	else if (spec.flags & 2)
		spec.sign = '+';
	else if (spec.flags & 4)
		spec.sign = ' ';
	sign = *str == '-' ? 1 : 0;
	len_s = max((int)ft_strlen(str + sign), spec.accur);
	len_s += spec.sign != 0 ? 1 : 0;
	if (!(s = ft_strfill('0', len_s)))
		return (0);
	ft_memcpy(s + len_s - (int)ft_strlen(str + sign), str + sign, \
	(int)ft_strlen(str));
	*s = spec.sign != 0 ? spec.sign : *s;
	free(str);
	s = handler_flags(s, spec);
	len = (int)ft_strlen(s);
	write(1, s, len);
	free(s);
	return (len);
}