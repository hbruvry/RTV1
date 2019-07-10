/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m3b3print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:38:20 by hbruvry           #+#    #+#             */
/*   Updated: 2018/11/16 17:28:55 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

/*
** Print 3b3 matrice
*/

/*
** 	ft_putchar('[');
** 	ft_putnbr(mat.m[0][0]);
** 	ft_putstr(", ");
** 	ft_putnbr(mat.m[0][1]);
** 	ft_putstr(", ");
** 	ft_putnbr(mat.m[0][2]);
** 	ft_putstr("]\n[");
** 	ft_putnbr(mat.m[1][0]);
** 	ft_putstr(", ");
** 	ft_putnbr(mat.m[1][1]);
** 	ft_putstr(", ");
** 	ft_putnbr(mat.m[1][2]);
** 	ft_putstr("]\n[");
** 	ft_putnbr(mat.m[2][0]);
** 	ft_putstr(", ");
** 	ft_putnbr(mat.m[2][1]);
** 	ft_putstr(", ");
** 	ft_putnbr(mat.m[2][2]);
** 	ft_putstr("]\n");
*/

void	ft_m3b3print(t_m3b3 mat)
{
	printf("[%f, %f, %f]\n", mat.m[0][0], mat.m[0][1], mat.m[0][2]);
	printf("[%f, %f, %f]\n", mat.m[1][0], mat.m[1][1], mat.m[1][2]);
	printf("[%f, %f, %f]\n", mat.m[2][0], mat.m[2][1], mat.m[2][2]);
	return ;
}
