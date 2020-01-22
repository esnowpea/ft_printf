/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgriseld <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:12:49 by dgriseld          #+#    #+#             */
/*   Updated: 2020/01/14 16:12:54 by dgriseld         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*   p       The void * pointer argument is printed in hexadecimal (as if by `%#x' or `%#lx').  */



int		ft_p(t_format_sp spec, va_list ap)
{
	void			*p;
	int 			len;
	unsigned long	q;
	char 			*s;

	p = va_arg(ap, void *);
	q = (unsigned long)p;
	spec.flags = 8;
	s = print_base_nbr(q, 0, spec);
	s = handler_flags(s, spec);
	len = (int)ft_strlen(s);
	write(1, s, len);
	free(s);
	return (len);
}
