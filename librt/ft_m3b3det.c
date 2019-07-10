/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m3b3det.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:14:30 by hbruvry           #+#    #+#             */
/*   Updated: 2018/11/16 18:18:37 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

/*
** Calcul 3b3 matrice determinant
*/

double	ft_m3b3det(t_m3b3 mat)
{
	double	det;

	det = mat.m[0][0] * mat.m[1][1] * mat.m[2][2]
	+ mat.m[1][0] * mat.m[2][1] * mat.m[0][2]
	+ mat.m[2][0] * mat.m[0][1] * mat.m[1][2]
	- mat.m[2][0] * mat.m[1][1] * mat.m[0][2]
	- mat.m[1][0] * mat.m[0][1] * mat.m[2][2]
	- mat.m[0][0] * mat.m[2][1] * mat.m[1][2];
	return (det);
}
