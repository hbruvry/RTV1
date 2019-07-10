/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m4b4set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:15:20 by hbruvry           #+#    #+#             */
/*   Updated: 2018/11/20 12:33:24 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

/*
** Set 4b4 matrice acocrding to bloc, botvec, rightvec and ncorner;
*/

t_m4b4	ft_m4b4set(t_m3b3 bloc, t_vec botvec, t_vec rightvec, double ncorner)
{
	t_m4b4	mat;

	mat.m[0][0] = bloc.m[0][0];
	mat.m[1][0] = bloc.m[1][0];
	mat.m[2][0] = bloc.m[2][0];
	mat.m[3][0] = botvec.x;
	mat.m[0][1] = bloc.m[0][1];
	mat.m[1][1] = bloc.m[1][1];
	mat.m[2][1] = bloc.m[2][1];
	mat.m[3][1] = botvec.y;
	mat.m[0][2] = bloc.m[0][2];
	mat.m[1][2] = bloc.m[1][2];
	mat.m[2][2] = bloc.m[2][2];
	mat.m[3][2] = botvec.z;
	mat.m[0][3] = rightvec.x;
	mat.m[1][3] = rightvec.y;
	mat.m[2][3] = rightvec.z;
	mat.m[3][3] = ncorner;
	return (mat);
}
