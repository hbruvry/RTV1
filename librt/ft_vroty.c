/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vroty.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 12:55:49 by hbruvry           #+#    #+#             */
/*   Updated: 2018/11/15 18:06:34 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

/*
** Rotate a 3b3 vector on y-axis according to r
*/

t_vec	ft_vroty(t_vec vec, double r)
{
	t_vec	vecrot;

	vecrot.x = vec.x * cos(r) + vec.z * sin(r);
	vecrot.y = vec.y;
	vecrot.z = vec.z * cos(r) - vec.x * sin(r);
	return (vecrot);
}
