/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgriseld <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:50:40 by dgriseld          #+#    #+#             */
/*   Updated: 2020/01/20 15:50:42 by dgriseld         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_x2(t_format_sp spec, va_list ap)
{
	int 				len;
	unsigned long long	p;
	char 				*s;

	if (!(p = ft_d_size_unsig(spec, ap)))
		return (-1);
	s = print_base_nbr(p, 1, spec);
	s = handler_flags(s, spec);
	len = (int)ft_strlen(s);
	write(1, s, len);
	free(s);
	return (len);
}