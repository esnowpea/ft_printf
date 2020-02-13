/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_e.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:56:42 by esnowpea          #+#    #+#             */
/*   Updated: 2020/02/13 17:01:37 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 		kol_nl(unsigned long long a)
{
	int	i;

	i = 0;
	while (a > 0)
	{
		a /= 10;
		i++;
	}
	return (i);
}

int 		shift_e(t_double *a)
{
	int		k;
	int 	i;
	int 	len;

	k = 0;
	i = 0;
	while (i < MAX_NB)
	{
		if ((*a).mod_array[i] != 0)
		{
			len = kol_nl((*a).mod_array[i]);
			while (k < (MAX_NB - 1 - i) * nl(MAX_NL) + len - 1)
			{
				*a = shift_double_right(*a);
				k++;
			}
			return (k);
		}
		i++;
	}
	i = 0;
	while (i < MAX_NB)
	{
		if ((*a).div_array[i] != 0)
		{
			len = kol_nl((*a).div_array[i]);
			while (k >  (i - 1) * nl(MAX_NL) + len - 1)
			{
				*a = shift_double_left(*a);
				k--;
			}
			return (k);
		}
		i++;
	}
	return (k);
}

char 		*add_e(char *str, int k)
{
	char	*s;
	int 	len;

	len = ft_strlen(str) + (k > 0 ? 0 : 1) + 4;
	if (!(s = ft_strnew(len)))
		return (0);
	ft_memcpy(s, str, ft_strlen(str));
	free(str);
	s[ft_strlen(s)] = 'e';
	if (k < 0)
	{
		s[ft_strlen(s)] = '-';
		k = k > 0 ? k : -k;
	}
	else
		s[ft_strlen(s)] = '+';
	if (kol_nl(k) < 3)
	{
		s[ft_strlen(s)] = k / 10 + '0';
		s[ft_strlen(s)] = k % 10 + '0';
	}
	else
	{
		s[ft_strlen(s)] = k / 100 + '0';
		s[ft_strlen(s)] = k / 10 % 10 + '0';
		s[ft_strlen(s)] = k % 10 + '0';
	}
	return (s);
}

char		*itoa_double_e(t_double a, int accur, char *sign)
{
	int		len;
	int		k;
	char 	*str;

	k = shift_e(&a);
	a = rounding(a, accur);
	len = accur + ft_strlen(sign) + 2;
	if (a.nan == '+')
		return (ft_strdup("inf"));
	else if (a.nan == '-')
		return (ft_strdup("-inf"));
	else if (a.nan == 'n')
		return (ft_strdup("nan"));
	else if (!(str = double_to_str(a, len, sign)))
		return (0);
	return (add_e(str, k));
}

t_str_len	ft_e(t_format_sp spec, va_list ap)
{
	t_long_a		nb;
	t_str_len		s;

	if (spec.accur == -1)
		spec.accur = 6;
	if (spec.size & 16)
		nb.db = va_arg(ap, long double);
	else
		nb.db = (long double)va_arg(ap, double);
	if (nb.db < 0)
		*spec.sign = '-';
	if (nb.db >= 0 && (spec.flags & 4))
		*spec.sign = ' ';
	if (nb.db >= 0 && (spec.flags & 2))
		*spec.sign = '+';
	s.str = itoa_double_e(mant_double(nb.number.sign, nb.number.exp - 16383,\
			nb.number.mant), spec.accur, spec.sign);
	if (spec.accur == 0 && !(spec.flags & 8))
		ft_memcpy(ft_strchr(s.str, '.'),ft_strchr(s.str, '.') + 1, ft_strlen(ft_strchr(s.str, '.') + 1));
	return (handler_flags(s.str, spec));
}
