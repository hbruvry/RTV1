/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vrotxyz.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 12:55:49 by hbruvry           #+#    #+#             */
/*   Updated: 2018/11/15 18:05:53 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

/*
** Rotate a 3b3 vector according to r.x, r.y and r.z
*/

t_vec	ft_vrotxyz(t_vec vec, t_vec r)
{
	vec = ft_vrotx(vec, r.x);
	vec = ft_vroty(vec, r.y);
	vec = ft_vrotz(vec, r.z);
	return (vec);
}
