/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vtom4b4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:18:15 by hbruvry           #+#    #+#             */
/*   Updated: 2018/11/15 18:10:38 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

/*
** Pass vector though 4b4 matrice
*/

t_vec	ft_vtom4b4(t_vec vec, t_m4b4 mat)
{
	t_vec	tvec;

	tvec.x = vec.x * mat.m[0][0] + vec.y * mat.m[0][1]
	+ vec.z * mat.m[0][2] + mat.m[0][3];
	tvec.y = vec.x * mat.m[1][0] + vec.y * mat.m[1][1]
	+ vec.z * mat.m[1][2] + mat.m[1][3];
	tvec.z = vec.x * mat.m[2][0] + vec.y * mat.m[2][1]
	+ vec.z * mat.m[2][2] + mat.m[2][3];
	return (tvec);
}
