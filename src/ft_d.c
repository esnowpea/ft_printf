/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:37:18 by esnowpea          #+#    #+#             */
/*   Updated: 2020/01/16 19:04:27 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int						ft_len_n(unsigned long long int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static unsigned long long int	ft_prov(long long int n, int *minus)
{
	unsigned long long int	num;

	if (n < 0)
	{
		*minus = 1;
		num = (unsigned long long int)(-1 * n);
	}
	else
		num = (unsigned long long int)n;
	return (num);
}

char							*ft_itoa_long(long long int n)
{
	char					*str;
	int						minus;
	int						i;
	unsigned long long int	num;

	i = 0;
	minus = 0;
	num = ft_prov(n, &minus);
	if (!(str = (char*)malloc(ft_len_n(num) + minus + 1)))
		return (0);
	i = ft_len_n(num) + minus;
	str[i--] = '\0';
	if (num == 0)
		str[i--] = '0';
	while (num)
	{
		str[i--] = (char)(num % 10 + 48);
		num /= 10;
	}
	if (minus)
		str[i--] = '-';
	return (str);
}


char 	*ft_d_size(t_format_sp spec, va_list ap)
{
	if (spec.size & 1)
		return (ft_itoa_long((long long int)va_arg(ap, long int)));
	else if (spec.size & 2)
		return (ft_itoa_long((long long int)va_arg(ap, long long int)));
	else if (spec.size & 4)
		return (ft_itoa_long((long long int)((short int)va_arg(ap, int))));
	else if (spec.size & 8)
		return (ft_itoa_long((long long int)((char)va_arg(ap, int))));
	else
		return (ft_itoa_long((long long int)va_arg(ap, int)));
}

int		ft_d(t_format_sp spec, va_list ap)
{
	char 			*str;
	char 			*s;
	char 			*start;
	int 			len;
	int 			len_s;
	int 			minus;

	if (!(str = ft_d_size(spec, ap)))
		return (-1);
	minus = *str == '-' ? 1 : 0;
	len_s = max((int)ft_strlen(str), spec.accur);
	len = max(len_s, spec.width);
	if (!(s = ft_strfill(' ', len)))
		return (-1);
	start = s;
	if (!minus && (spec.flags & 2))
	{
		*s = '+';
		s++;
	}
	if (!minus && (spec.flags & 4))
		s++;
	while (((spec.flags & 1) == 0) && ((int)ft_strlen(s) != (len_s)))
		s++;
	if (minus)
	{
		*s = *str;
		s++;
		str++;
	}
	while (ft_strlen(s) != ft_strlen(str))
	{
		*s = '0';
		s++;
	}
	ft_strcpy(s, str);
	if (minus)
		free(--str);
	else
		free(str);
	write(1, start, len);
	free(start);
	return (len); //TODO No WORK. PLEASE FIX
}