/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m3b3set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:15:20 by hbruvry           #+#    #+#             */
/*   Updated: 2018/12/17 10:13:19 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

/*
** Set 3b3 matrice acocrding to veca, vecb, vecc vectors
*/

t_m3b3	ft_m3b3set(t_vec veca, t_vec vecb, t_vec vecc)
{
	t_m3b3	mat;

	mat.m[0][0] = veca.x;
	mat.m[1][0] = veca.y;
	mat.m[2][0] = veca.z;
	mat.m[0][1] = vecb.x;
	mat.m[1][1] = vecb.y;
	mat.m[2][1] = vecb.z;
	mat.m[0][2] = vecc.x;
	mat.m[1][2] = vecc.y;
	mat.m[2][2] = vecc.z;
	return (mat);
}
