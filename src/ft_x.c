/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgriseld <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:46:22 by dgriseld          #+#    #+#             */
/*   Updated: 2020/01/20 15:46:25 by dgriseld         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_x(t_format_sp spec, va_list ap)
{
	void			*p;
	int 			len;
	unsigned int	q;
	char 			*s;

	p = va_arg(ap, unsigned int);
	len = print_base_nbr(p, 0, spec);
	s = handler_flags(s, spec);
	len = (int)ft_strlen(s);
	write(1, s, len);
	free(s);
	return (len);
}
