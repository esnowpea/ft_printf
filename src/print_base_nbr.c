/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgriseld <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 14:59:42 by dgriseld          #+#    #+#             */
/*   Updated: 2020/01/20 14:59:48 by dgriseld         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int print(unsigned int a, int base, char alph[15], t_format_sp spec)
{
	int 	j;
	int 	i;
	char 	tmp[34];
	char 	*str;

	j = 0;
	while(a / base > 0)
	{
		tmp[j] = alph[a % base];
		a = a / base;
		j++;
	}
	tmp[j] = alph[a % base];
	str = ft_strnew(34);
	i = 0;
	if (spec. == 8 && (spec.flags && 16))
	while (j >= 0)
	{
		write(1, &str[j],1);
		j--;
	}
	return (t);
}

char				*print_base_nbr(unsigned int a, int q, t_format_sp spec)
{
	char			alph[] = "0123456789abcdef";
	char			alph2[] = "0123456789ABCDEF";

	if (spec.base == 16 && (spec.flags && 16))
	{
		write(1, "0x", 2);
	}
	else if (base == 8 && (spec.flags && 16))
	{
		write(1, "0",1);
	}
	if (q == 0)
		print(a, base,alph);
	else if (q == 1)
		print(a, base,alph2);
	return ();
}
