/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m3b3inv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:15:56 by hbruvry           #+#    #+#             */
/*   Updated: 2018/11/16 18:18:34 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

/*
** Invert 3b3 matrice
*/

t_m3b3	ft_m3b3inv(t_m3b3 mat)
{
	t_m3b3	tmat;
	double	det;

	tmat = ft_m3b3set(ft_vset(0, 0, 0), ft_vset(0, 0, 0), ft_vset(0, 0, 0));
	if (!(det = ft_m3b3det(mat)))
		return (tmat);
	tmat.m[0][0] = mat.m[1][1] * mat.m[2][2] - mat.m[2][1] * mat.m[1][2];
	tmat.m[0][1] = mat.m[2][1] * mat.m[0][2] - mat.m[0][1] * mat.m[2][2];
	tmat.m[0][2] = mat.m[0][1] * mat.m[1][2] - mat.m[1][1] * mat.m[0][2];
	tmat.m[1][0] = mat.m[2][0] * mat.m[1][2] - mat.m[1][0] * mat.m[2][2];
	tmat.m[1][1] = mat.m[0][0] * mat.m[2][2] - mat.m[2][0] * mat.m[0][2];
	tmat.m[1][2] = mat.m[1][0] * mat.m[0][2] - mat.m[0][0] * mat.m[1][2];
	tmat.m[2][0] = mat.m[1][0] * mat.m[2][1] - mat.m[2][0] * mat.m[1][1];
	tmat.m[2][1] = mat.m[2][0] * mat.m[0][1] - mat.m[0][0] * mat.m[2][1];
	tmat.m[2][2] = mat.m[0][0] * mat.m[1][1] - mat.m[1][0] * mat.m[0][1];
	tmat = ft_m3b3scale(tmat, 1 / det);
	return (tmat);
}
