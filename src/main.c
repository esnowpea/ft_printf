/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:00:04 by esnowpea          #+#    #+#             */
/*   Updated: 2020/01/14 15:26:04 by esnowpea         ###   ########.fr       */
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
	char str[] = "Hello World! %% %-10.6s\n";
	char arg[] = "asd123tyu0";
	ft_printf(str, arg);
	printf(str, arg);
}