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
	int 			count;
	unsigned int	q;

	(void)spec;
	p = va_arg(ap, void *);
	q = (unsigned int)p;
	count = print_base_nbr(q, 16, 0);
	return (count);
}
