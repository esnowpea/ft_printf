/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_double.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:10:48 by esnowpea          #+#    #+#             */
/*   Updated: 2020/02/12 16:33:51 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	len_mod(t_double a)
{
	int i;
	unsigned long long int j;
	int len;

	len = 0;
	i = 0;
	while (i < MAX_NB && a.mod_array[i] == 0)
		i++;
	while (i < MAX_NB)
	{
		j = MAX_NL / 10;
		while (j > 0)
		{
			if (a.mod_array[i] / j != 0 || len > 0)
				len++;
			a.mod_array[i] %= j;
			j /= 10;
		}
		i++;
	}
	if (len == 0)
		len++;
	return (len);
}

char	*double_to_str(t_double a, int len, char* sign)
{
	char	*str;
	int i;
	unsigned long long int j;
	int k;

	if (!(str = ft_strnew(len)))
		return (0);
	i = 0;
	k = 0;
	if (ft_strlen(sign))
		str[k++] = *sign;
	while (i < MAX_NB && a.mod_array[i] == 0)
		i++;
	while (i < MAX_NB)
	{
		j = MAX_NL / 10;
		while (j > 0)
		{
			if (a.mod_array[i] / j != 0 || k > (int)ft_strlen(sign))
				str[k++] = a.mod_array[i] / j + '0';
			a.mod_array[i] %= j;
			j /= 10;
		}
		i++;
	}
	if (k == (int)ft_strlen(sign))
		str[k++] = '0';
	str[k++] = '.';
	i = 0;
	while (i < MAX_NB && k < len)
	{
		j = MAX_NL / 10;
		while (j > 0 && k < len)
		{
			str[k++] = a.div_array[i] / j + '0';
			a.div_array[i] %= j;
			j /= 10;
		}
		i++;
	}
	return (str);
}

int 	nl(unsigned long long int j)
{
	int i;

	i = 0;
	while (j > 1)
	{
		i++;
		j /= 10;
	}
	return (i);
}

int 	rod(t_double a, int accur)
{
	int i;
	unsigned long long int j;

	if (accur % nl(MAX_NL) == 0)
		return ((int)(a.div_array[accur / nl(MAX_NL) - 1] % 10));
	i = 0;
	j = a.div_array[accur / nl(MAX_NL)];
	while (i < nl(MAX_NL) - accur % nl(MAX_NL))
	{
		j /= 10;
		i++;
	}
	return ((int)(j % 10));
}

t_double rounding_plus(t_double a, int accur)
{
	int i;
	t_double b;

	b = first_double();
	i = 0;
	while (i < accur)
	{
		b = shift_double_right(b);
		i++;
	}
	return (sum_double(a, b));
}

t_double rounding(t_double a, int accur)
{
	int 	i;

	if (rod(a, accur + 1) > 5)
		return (rounding_plus(a, accur));//todo up
	else if	(rod(a, accur + 1) < 5)
		return (a);
	else
	{
		i = accur + 2;
		while (i % nl(MAX_NL))
		{
			if (rod(a, i) != 0)
				return (rounding_plus(a, accur));
			i++;
		}
		if (rod(a, i + 1) != 0)
			return (rounding_plus(a, accur));
		i = accur / nl(MAX_NL) == 0 ? accur / nl(MAX_NL) + 1 : accur / nl(MAX_NL);
		while (i < MAX_NB)
		{
			if (a.div_array[i] != 0)
				return (rounding_plus(a, accur));
			i++;
		}
	}
	return (a);
}

char	*itoa_double(t_double a, int accur, char* sign)
{
	int len;

	a = rounding(a, accur);
	len = len_mod(a);
	len += accur + 1 + ft_strlen(sign);
	return (double_to_str(a, len, sign));
}