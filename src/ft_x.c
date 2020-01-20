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
	int 			count;
	unsigned int	q;

	(void)spec;
	p = va_arg(ap, unsigned int);
	count = print_base_nbr(p, 16, 0);
	return (count);
}
