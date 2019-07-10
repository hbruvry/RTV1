/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m4b4print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:38:20 by hbruvry           #+#    #+#             */
/*   Updated: 2018/11/16 17:20:13 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

/*
** Print 4b4 matrice
*/

/*
** 	ft_putchar('[');
** 	ft_putnbr(mat.m[0][0]);
** 	ft_putstr(", ");
** 	ft_putnbr(mat.m[0][1]);
** 	ft_putstr(", ");
** 	ft_putnbr(mat.m[0][2]);
** 	ft_putstr(", ");
** 	ft_putnbr(mat.m[0][3]);
** 	ft_putstr("]\n[");
** 	ft_putnbr(mat.m[1][0]);
** 	ft_putstr(", ");
** 	ft_putnbr(mat.m[1][1]);
** 	ft_putstr(", ");
** 	ft_putnbr(mat.m[1][2]);
** 	ft_putstr(", ");
** 	ft_putnbr(mat.m[1][3]);
** 	ft_putstr("]\n[");
** 	ft_putnbr(mat.m[2][0]);
** 	ft_putstr(", ");
** 	ft_putnbr(mat.m[2][1]);
** 	ft_putstr(", ");
** 	ft_putnbr(mat.m[2][2]);
** 	ft_putstr(", ");
** 	ft_putnbr(mat.m[2][3]);
** 	ft_putstr("]\n[");
** 	ft_putnbr(mat.m[3][0]);
** 	ft_putstr(", ");
** 	ft_putnbr(mat.m[3][1]);
** 	ft_putstr(", ");
** 	ft_putnbr(mat.m[3][2]);
** 	ft_putstr(", ");
** 	ft_putnbr(mat.m[3][3]);
** 	ft_putstr("]\n");
*/

void	ft_m4b4print(t_m4b4 mat)
{
	printf("[%f, %f, %f, %f]\n", mat.m[0][0], mat.m[0][1], mat.m[0][2],
		mat.m[0][3]);
	printf("[%f, %f, %f, %f]\n", mat.m[1][0], mat.m[1][1], mat.m[1][2],
		mat.m[1][3]);
	printf("[%f, %f, %f, %f]\n", mat.m[2][0], mat.m[2][1], mat.m[2][2],
		mat.m[2][3]);
	printf("[%f, %f, %f, %f]\n", mat.m[3][0], mat.m[3][1], mat.m[3][2],
		mat.m[3][3]);
	return ;
}
