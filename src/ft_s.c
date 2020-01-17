/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:05:34 by esnowpea          #+#    #+#             */
/*   Updated: 2020/01/17 16:36:13 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_s(t_format_sp spec, va_list ap)
{
	char	*s;
	char 	*str;
	int		len;

	str = va_arg(ap, char*);
	len = min((int)ft_strlen(str), spec.accur);
	s = ft_strnew(len);
	ft_memcpy(s, str, len);
	s = handler_flags(s, spec);
	len = (int)ft_strlen(s);
	write(1, s, len);
	free(s);
	return (len);
}
