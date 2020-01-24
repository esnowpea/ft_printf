/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:05:34 by esnowpea          #+#    #+#             */
/*   Updated: 2020/01/24 15:18:13 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_s(t_format_sp spec, va_list ap)
{
	t_str_len	s;
	char		*str;

	if (!(str = va_arg(ap, char*)))
		str = "(null)";
	if (spec.accur >= 0)
		s.len = min((int)ft_strlen(str), spec.accur);
	else
		s.len = (int)ft_strlen(str);
	if (!(s.str = ft_strnew(s.len)))
		return (-1);
	ft_memcpy(s.str, str, s.len);
	s = handler_flags(s.str, spec);
	write(1, s.str, s.len);
	free(s.str);
	return (s.len);
}
