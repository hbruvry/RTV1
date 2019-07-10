/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m3b3mul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:18:15 by hbruvry           #+#    #+#             */
/*   Updated: 2018/11/15 18:21:22 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

/*
** Multiply two 3b3 matrices
*/

t_m3b3	ft_m3b3mul(t_m3b3 mata, t_m3b3 matb)
{
	t_m3b3	tmat;
	t_vec	vecx;
	t_vec	vecy;
	t_vec	vecz;

	vecx = ft_vset(matb.m[0][0], matb.m[1][0], matb.m[2][0]);
	vecy = ft_vset(matb.m[0][1], matb.m[1][1], matb.m[2][1]);
	vecz = ft_vset(matb.m[0][2], matb.m[1][2], matb.m[2][2]);
	tmat = ft_m3b3set(ft_vtom3b3(vecx, mata), ft_vtom3b3(vecy, mata),
			ft_vtom3b3(vecz, mata));
	return (tmat);
}
