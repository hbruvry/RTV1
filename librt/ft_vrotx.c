/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vrotx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 12:55:49 by hbruvry           #+#    #+#             */
/*   Updated: 2018/11/15 18:05:28 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

/*
** Rotate a 3b3 vector on x-axis according to r
*/

t_vec	ft_vrotx(t_vec vec, double r)
{
	t_vec	vecrot;

	vecrot.x = vec.x;
	vecrot.y = vec.y * cos(r) - vec.z * sin(r);
	vecrot.z = vec.z * cos(r) + vec.y * sin(r);
	return (vecrot);
}
