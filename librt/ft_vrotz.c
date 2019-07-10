/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vrotZ.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 12:55:49 by hbruvry           #+#    #+#             */
/*   Updated: 2018/11/15 18:07:18 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

/*
** Rotate a 3b3 vector on z-axis according to r
*/

t_vec	ft_vrotz(t_vec vec, double r)
{
	t_vec	vecrot;

	vecrot.x = vec.x * cos(r) - vec.y * sin(r);
	vecrot.y = vec.y * cos(r) + vec.x * sin(r);
	vecrot.z = vec.z;
	return (vecrot);
}
