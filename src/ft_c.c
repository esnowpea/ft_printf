/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 11:59:57 by esnowpea          #+#    #+#             */
/*   Updated: 2020/01/14 12:49:26 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char 	*ft_strfill(char c, int length)
{
	char 	*str;
	int		i;

	str = (char*)malloc(sizeof(char) * (length + 1));
	if (!str)
		return (0);
	i = 0;
	while (i < length)
		str[i++] = c;
	str[i] = '\0';
	return (str);
}

int		ft_c(t_format_sp spec, va_list ap)
{
	char	c;
	char 	*str;
	int 	count;

	c = va_arg(ap, int);
	count = 1;
	if (spec.width > 0)
	{
		if (!(str = ft_strfill(' ', spec.width)))
			return (-1);
		count = spec.width;
		if ((spec.flags & 1) == 1)
			str[0] = c;
		else
			str[spec.width - 1] = c;
		write(1, str, count);
		free(str);
	}
	else
		write(1, &c, count);
	return (count);
}
