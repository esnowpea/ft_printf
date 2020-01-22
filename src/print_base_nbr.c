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

static char	*get_str(unsigned long a, const char alph[17], t_format_sp spec)
{
	int 	j;
	int 	i;
	char 	tmp[34];
	char 	*str;

	j = 0;
	while(a / spec.base > 0)
	{
		tmp[j] = alph[a % spec.base];
		a = a / spec.base;
		j++;
	}
	tmp[j] = alph[a % spec.base];
	str = ft_strnew(34);
	i = -1;
	if ((spec.base == 8 || spec.base == 16) && (spec.flags & 8))
	{
		str[++i] = '0';
		if (spec.base == 16 && alph[15] == 'f')
			str[++i] = 'x';
		else if(spec.base == 16 && alph[15] == 'F')
			str[++i] = 'X';
	}
	while (j >= 0)
	{
		str[++i] = tmp[j];
		j--;
	}
	return (str);
}

char				*print_base_nbr(unsigned long long a, int q, t_format_sp spec)
{
	const char			alph[] = "0123456789abcdef";
	const char			alph2[] = "0123456789ABCDEF";
	char 			*str;

	str = NULL;
	if (q == 0)
		str = get_str(a, alph, spec);
	else if (q == 1)
		str = get_str(a, alph2, spec);
	return (str);
}
