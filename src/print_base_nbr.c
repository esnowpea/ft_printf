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

static int print(unsigned int a, int base, char alph[15])
{
	int 	j;
	int 	t;
	char 	str[31];

	j = 0;
	while(a / base > 0)
	{
		str[j] = alph[a % base];
		a = a / base;
		j++;
	}
	str[j] = alph[a % base];
	t = j;
	while (j >= 0)
	{
		write(1, &str[j],1);
		j--;
	}
	return (t);
}

int	print_base_nbr(unsigned int a, int base, int q)
{
	char			alph[] = "0123456789abcdef";
	char			alph2[] = "0123456789ABCDEF";
	unsigned int	i;

	if (base == 16)
	{
		write(1, "0x", 2);
		i = 2;
	}
	else if (base == 8)
	{
		write(1, "0",1);
		i = 1;
	}
	if (q == 0)
		i += print(a, base,alph);
	else if (q == 1)
		i += print(a, base,alph2);
	return (i);
}
