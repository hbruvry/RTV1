/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vnorm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 12:55:49 by hbruvry           #+#    #+#             */
/*   Updated: 2018/11/15 18:03:42 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

/*
** Normalize a 3b3 vectors
*/

t_vec	ft_vnorm(t_vec vec)
{
	double	n;

	n = sqrt(ft_vsqrd(vec));
	vec.x /= n;
	vec.y /= n;
	vec.z /= n;
	return (vec);
}
