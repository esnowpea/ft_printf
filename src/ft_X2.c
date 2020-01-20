/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgriseld <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:50:40 by dgriseld          #+#    #+#             */
/*   Updated: 2020/01/20 15:50:42 by dgriseld         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_x2(t_format_sp spec, va_list ap)
{
	void			*p;
	int 			count;
	unsigned int	q;

	(void)spec;
	p = va_arg(ap, unsigned int);
	count = print_base_nbr(p, 16, 1);
	return (count);
}