/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vpolartocartesian.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 14:09:33 by hbruvry           #+#    #+#             */
/*   Updated: 2018/11/16 16:06:21 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

/*
** Convert a 3b3 polar vectors containing radius, longitude & latitude
** into a vector containing cartsian coordinates
*/

t_vec	ft_vpolartocartesian(t_vec vec)
{
	t_vec	vecpol;

	vecpol.x = vec.x * sin(vec.y) * cos(vec.z);
	vecpol.y = vec.x * cos(vec.y);
	vecpol.z = vec.x * sin(vec.y) * sin(vec.z);
	return (vecpol);
}
