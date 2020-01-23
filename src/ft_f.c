/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:44:14 by esnowpea          #+#    #+#             */
/*   Updated: 2020/01/23 15:30:59 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int 	ft_f(t_format_sp spec, va_list ap)
{
	t_long_a	nb;

	if (spec.size & 16)
		nb.db = va_arg(ap, long double);
	else
		nb.db = (long double)va_arg(ap, double);
	return (1);
}
