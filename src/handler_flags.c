/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:24:26 by esnowpea          #+#    #+#             */
/*   Updated: 2020/01/24 15:24:27 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	FLAGS:
**	'-'	- 00001
**	'+'	- 00010
**	' '	- 00100
**	'#'	- 01000
**	'0'	- 10000
*/

void		up_to_low(char **s)
{
	int		i;
	int		len;
	char	*str;

	str = *s;
	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		str[i] = (str[i] >= 'A' && str[i] <= 'Z') ? str[i] + 32 : str[i];
		i++;
	}
}

t_str_len	handler_flags(char *str, t_format_sp spec)
{
	int			len_s;
	t_str_len	s;

	len_s = spec.type != 'c' ? (int)ft_strlen(str) : 1;
	s.len = max(len_s, spec.width);
	if (!(s.str = ft_strfill(' ', s.len)))
		return (s);//todo malloc
	if (spec.flags & 1)
		ft_memcpy(s.str, str, len_s);
	else
		ft_memcpy(s.str + s.len - len_s, str, len_s);
	if (spec.flags & 16 && spec.accur == -1 && !(spec.flags & 1))
	{
		ft_memset(s.str, '0', s.len - len_s);
		if (ft_strlen(spec.sign))
		{
			ft_memcpy(s.str + s.len - len_s, "00", ft_strlen(spec.sign));
			ft_memcpy(s.str, spec.sign, ft_strlen(spec.sign));
		}
	}
	if (spec.type == 'x' || spec.type == 'p')
		up_to_low(&s.str);
	free(str);
	return (s);
}
