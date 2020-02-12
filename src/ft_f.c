/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:44:14 by esnowpea          #+#    #+#             */
/*   Updated: 2020/02/12 17:08:54 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include "ft_printf.h"

t_double mant_double(int exp, unsigned long long mant);

t_str_len	ft_f(t_format_sp spec, va_list ap)
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
	s.str = itoa_double(mant_double(nb.number.exp - 16383, nb.number.mant),
			spec.accur, spec.sign);
	if (spec.accur == 0 && !(spec.flags & 8))
		s.str[--s.len] = '\0';
	return (handler_flags(s.str, spec));
}

t_double zero_double(void)
{
	int			i;
	t_double	num;

	i = 0;
	while (i < MAX_NB)
	{
		num.div_array[i] = 0;
		num.mod_array[i++] = 0;
	}
	return (num);
}

t_double sum_double(t_double a, t_double b)
{
	int			i;
	t_double	c;

	c = zero_double();
	i = MAX_NB - 1;
	while (i >= 0)
	{
		c.mod_array[i] += a.mod_array[i] + b.mod_array[i];
		c.div_array[i] += a.div_array[i] + b.div_array[i];
		if (c.mod_array[i] > MAX_NL - 1)
		{
			c.mod_array[i - 1] += c.mod_array[i] / MAX_NL;
			c.mod_array[i] %= MAX_NL;
		}
		if (c.div_array[i] > MAX_NL - 1)
		{
			c.div_array[i - 1] += c.div_array[i] / MAX_NL;
			c.div_array[i] %= MAX_NL;
		}
		if (i == 0 && c.div_array[i] > MAX_NL - 1)
		{
			c.mod_array[MAX_NB - 1] += c.div_array[i] / MAX_NL;
			c.div_array[i] %= MAX_NL;
		}
		i--;
	}
	return(c);
}

t_double mult_double(t_double a, unsigned int b)
{
	int			i;
	t_double	c;

	c = zero_double();
	i = MAX_NB - 1;
	while (i >= 0)
	{
		c.mod_array[i] += a.mod_array[i] * b;
		c.div_array[i] += a.div_array[i] * b;
		if (i != 0 && c.mod_array[i] > MAX_NL - 1)
		{
			c.mod_array[i - 1] += c.mod_array[i] / MAX_NL;
			c.mod_array[i] %= MAX_NL;
		}
		if (i != 0 && c.div_array[i] >= MAX_NL)
		{
			c.div_array[i - 1] += c.div_array[i] / MAX_NL;
			c.div_array[i] %= MAX_NL;
		}
		if (i == 0 && c.div_array[i] >= MAX_NL)
		{
			c.mod_array[MAX_NB - 1] += c.div_array[i] / MAX_NL;
			c.div_array[i] %= MAX_NL;
		}
		i--;
	}
	return (c);
}

t_double shift_double_right(t_double a)
{
	int i;

	i = MAX_NB - 1;
	a.div_array[i] /= 10;
	i--;
	while (i >= 0)
	{
		a.div_array[i + 1] += a.div_array[i] % 10 * MAX_NL / 10;
		a.div_array[i--] /= 10;
	}
	i = MAX_NB - 1;
	a.div_array[0] += a.mod_array[i] % 10 * MAX_NL / 10;
	a.mod_array[i] /= 10;
	i--;
	while (i >= 0)
	{
		a.mod_array[i + 1] += a.mod_array[i] % 10 * MAX_NL / 10;
		a.mod_array[i--] /= 10;
	}
	return (a);
}

t_double first_double(void)
{
	int			i;
	t_double	num;

	i = 0;
	while (i < MAX_NB)
	{
		num.div_array[i] = 0;
		num.mod_array[i++] = 0;
	}
	num.mod_array[MAX_NB - 1] = 1;
	return (num);
}

t_double power_two(int n)
{
	int			i;
	t_double	a;

	a = first_double();
	i = 0;
	while (i < n && n > 0)
	{
		a = mult_double(a, 2);
		i++;
	}
	while (i < -n && n <= 0)
	{
		a = shift_double_right(mult_double(a, 5));
		i++;
	}
	return (a);
}

t_double mant_double(int exp, unsigned long long mant)
{
	int i;
	t_double a;
	char s[64];

	i = 0;
	while (i < 64)
	{
		s[i++] = mant % 2 + '0';
		mant /= 2;
	}
	i = 63;
	a = zero_double();
	while (i >= 0)
	{
		if (s[i] == '1')
			a = sum_double(a, power_two(exp + i - 63));
		i--;
	}
	return (a);
}

void	ft_putnbr1(unsigned long long int num, int fd)
{
	if (num < 10)
		ft_putchar_fd(num + '0', fd);
	else
	{
		ft_putnbr1((unsigned long long int)(num / 10), fd);
		ft_putchar_fd(num % 10 + '0', fd);
	}
}

void 	out_double_fd(t_double a, int fd)
{
	int i;
	unsigned long long int j;

	i = 0;
	while (i < MAX_NB && a.mod_array[i] == 0)
		i++;
	if (i < MAX_NB)
		ft_putnbr1(a.mod_array[i++], fd);
	while (i < MAX_NB)
	{
		j = MAX_NL / 10;
		while (j > 0)
		{
			ft_putnbr1(a.mod_array[i] / j, fd);
			a.mod_array[i] %= j;
			j /= 10;
		}
		i++;
	}
	ft_putchar_fd('.', fd);
	i = 0;
	while (i < MAX_NB)
	{
		j = MAX_NL / 10;
		while (j > 0)
		{
			ft_putnbr1(a.div_array[i] / j, fd);
			a.div_array[i] %= j;
			j /= 10;
		}
		i++;
	}
}
