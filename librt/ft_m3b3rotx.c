/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m3b3rotx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:14:54 by hbruvry           #+#    #+#             */
/*   Updated: 2018/11/15 16:31:49 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

/*
** Rotate 3b3 matrice on x axis
*/

t_m3b3	ft_m3b3rotx(double theta)
{
	double	cost;
	double	sint;
	t_m3b3	mat;

	mat = ft_m3b3set(ft_vset(0, 0, 0), ft_vset(0, 0, 0), ft_vset(0, 0, 0));
	cost = cosf(theta);
	sint = sinf(theta);
	mat = ft_m3b3set(ft_vset(1, 0, 0), ft_vset(0, cost, sint),
		ft_vset(0, -sint, cost));
	return (mat);
}
