/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m3b3setdiag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:46:27 by hbruvry           #+#    #+#             */
/*   Updated: 2018/11/16 10:51:45 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

/*
** Set diagonal 3b3 matrices
*/

t_m3b3	ft_m3b3setdiag(t_vec vec)
{
	t_m3b3	mat;
	t_vec	vecx;
	t_vec	vecy;
	t_vec	vecz;

	vecx = ft_vset(vec.x, 0, 0);
	vecy = ft_vset(0, vec.y, 0);
	vecz = ft_vset(0, 0, vec.z);
	mat = ft_m3b3set(vecx, vecy, vecz);
	return (mat);
}
