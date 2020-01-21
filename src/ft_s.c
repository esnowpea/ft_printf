/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:05:34 by esnowpea          #+#    #+#             */
/*   Updated: 2020/01/21 15:58:19 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_s(t_format_sp spec, va_list ap)
{
	char	*s;
	char 	*str;
	int		len;

	if (!(str = va_arg(ap, char*)))
		str = "(null)";
	if (spec.accur >= 0)
		len = min((int)ft_strlen(str), spec.accur);
	else
		len = (int)ft_strlen(str);
	s = ft_strnew(len); //TODO malloc
	ft_memcpy(s, str, len);
	s = handler_flags(s, spec);
	len = (int)ft_strlen(s);
	write(1, s, len);
	free(s);
	return (len);
}
