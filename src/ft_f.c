/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:44:14 by esnowpea          #+#    #+#             */
/*   Updated: 2020/01/21 17:54:14 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

static int	ft_len_n(long double n, int base)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= base;
		i++;
	}
	return (i);
}

t_long_a	double_to_long_a(long double numb)
{
	t_long_a	nb;

	nb.sign = 1;
	if (numb < 0)
	{
		nb.sign = -1;
		numb = -numb;
	}
	nb.bits = (unsigned int*)malloc(sizeof(unsigned int) * ft_len_n(numb, 10));
	return (nb);
}

int 	ft_f(t_format_sp spec, va_list ap)
{
	long double numb;
	t_long_a	nb;

	if (spec.size & 16)
		numb = va_arg(ap, long double);
	else
		numb = (long double)va_arg(ap, double);
	nb = double_to_long_a(numb);
	return (1);
}
