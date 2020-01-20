/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_0.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgriseld <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:36:31 by dgriseld          #+#    #+#             */
/*   Updated: 2020/01/20 15:36:34 by dgriseld         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_o(t_format_sp spec, va_list ap)
{
	void			*p;
	int 			count;
	unsigned int	q;

	(void)spec;
	p = va_arg(ap, unsigned int);
	count = print_base_nbr(p, 8, 0);
	return (count);
}
