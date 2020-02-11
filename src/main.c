/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:00:04 by esnowpea          #+#    #+#             */
/*   Updated: 2020/02/11 19:21:33 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>

void		out_double_fd(t_double a, int fd);
t_double	sum_double(t_double a, t_double b);
t_double	power_two(int n);

int main()
{
	t_double b;

	ft_printf("%f\n", 3.1415161718191);
	return (0);
}