/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vmul.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 12:55:49 by hbruvry           #+#    #+#             */
/*   Updated: 2018/11/15 18:03:23 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

/*
** Multiply a 3b3 vectors according to o
*/

t_vec	ft_vmul(t_vec vec, double o)
{
	vec.x *= o;
	vec.y *= o;
	vec.z *= o;
	return (vec);
}
