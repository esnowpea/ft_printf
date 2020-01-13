/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:00:04 by esnowpea          #+#    #+#             */
/*   Updated: 2019/12/25 16:06:46 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>


unsigned int x22(unsigned int k)
{
	unsigned int out;
	unsigned int l;

	out = 0;
	l = 1 << 31;
	while (!(k & l) && l)
	{
		l = l >> 1;
	}
	//if (l == 0)
		//write(1, "0", 1);
	while (l)
	{
		if (k & l)
			out = out * 10 + 1;//write(1, "1", 1);
		else
			out = out * 10 + 0;//write(1, "0", 1);
		l = l >> 1;
	}
	return (out);
}


int main()
{
	ft_printf("Hello World! %% %- 20.3lld\n", 10);
	printf("%.s", "ycgjhjknk");
}