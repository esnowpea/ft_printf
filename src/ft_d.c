/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:37:18 by esnowpea          #+#    #+#             */
/*   Updated: 2020/01/16 16:59:55 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_d(t_format_sp spec, va_list ap)
{
	long long int	d;
	char 			*str;
	char 			*s;
	char 			*start;
	int 			len;
	int 			len_s;

	d = va_arg(ap, long long int);
	if (!(str = ft_itoa(d)))
		return (-1);
	len_s = max((int)ft_strlen(str), spec.accur);
	len = max(len_s, spec.width);
	if (!(s = ft_strfill(' ', len)))
		return (-1);
	start = s;
	if (d >= 0 && (spec.flags & 2))
	{
		*s = '+';
		s++;
	}
	if (d >= 0 && (spec.flags & 4))
		s++;

	while (((spec.flags & 1) == 0) && ft_strlen(s) != len_s)
		s++;
	while (ft_strlen(s) != ft_strlen(str))
	{
		*s = '0';
		s++;
	}
	ft_strcpy(s, str);
	free(str);
	write(1, start, len);
	free(start);
	return (len);
}