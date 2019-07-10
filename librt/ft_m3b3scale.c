/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m3b3scale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:16:25 by hbruvry           #+#    #+#             */
/*   Updated: 2018/11/16 14:15:03 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

/*
** Scale 3b3 matrice
*/

t_m3b3	ft_m3b3scale(t_m3b3 mat, double s)
{
	t_m3b3	tmat;

	tmat.m[0][0] = s * mat.m[0][0];
	tmat.m[0][1] = s * mat.m[0][1];
	tmat.m[0][2] = s * mat.m[0][2];
	tmat.m[1][0] = s * mat.m[1][0];
	tmat.m[1][1] = s * mat.m[1][1];
	tmat.m[1][2] = s * mat.m[1][2];
	tmat.m[2][0] = s * mat.m[2][0];
	tmat.m[2][1] = s * mat.m[2][1];
	tmat.m[2][2] = s * mat.m[2][2];
	return (tmat);
}
