/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:05:34 by esnowpea          #+#    #+#             */
/*   Updated: 2020/01/14 15:13:57 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define max(a, b) a > b ? a : b
#define min(a, b) a < b ? a : b

char 	*add_s_left(char *str, const char *s, int len_s)
{
	size_t 	i;

	i = 0;
	while (i < len_s)
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}

char 	*add_s_right(char *str, const char *s, int len_s)
{
	size_t	i;
	size_t	len;
	size_t	start;

	len = ft_strlen(str);
	start = len - len_s;
	i = start;
	while (i < len)
	{
		str[i] = s[i - start];
		i++;
	}
	return (str);
}

int		ft_s(t_format_sp spec, va_list ap)
{
	char	*s;
	char 	*str;
	int 	count;
	int		len_s;
	int		len;

	s = va_arg(ap, char*);
	len_s = min(spec.accur, ft_strlen(s));
	len = max(spec.width, len_s);
	if (!(str = ft_strfill(' ', len)))
		return (-1);
	if ((spec.flags & 1) == 1)
		str = add_s_left(str, s, len_s);
	else
		str = add_s_right(str, s, len_s);
	count = ft_strlen(str);
	write(1, str, count);
	free(str);
	return (count);
}
