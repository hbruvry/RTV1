/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m3b3rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:14:54 by hbruvry           #+#    #+#             */
/*   Updated: 2018/11/15 16:30:36 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

/*
** Rotate 3b3 matrice
*/

t_m3b3	ft_m3b3rot(double theta, int axis)
{
	double	cost;
	double	sint;
	t_m3b3	mat;

	mat = ft_m3b3set(ft_vset(0, 0, 0), ft_vset(0, 0, 0), ft_vset(0, 0, 0));
	if (axis < 0 || axis > 2)
		return (mat);
	cost = cosf(theta);
	sint = sinf(theta);
	if (axis == 0)
		mat = ft_m3b3set(ft_vset(1, 0, 0), ft_vset(0, cost, sint),
			ft_vset(0, -sint, cost));
	else if (axis == 1)
		mat = ft_m3b3set(ft_vset(cost, 0, -sint), ft_vset(0, 1, 0),
			ft_vset(sint, 0, cost));
	else
		mat = ft_m3b3set(ft_vset(cost, sint, 0), ft_vset(-sint, cost, 0),
			ft_vset(0, 0, 1));
	return (mat);
}
