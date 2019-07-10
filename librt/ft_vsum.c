/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 12:55:49 by hbruvry           #+#    #+#             */
/*   Updated: 2018/11/15 18:09:26 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

/*
** Add two 3b3 vectors
*/

t_vec	ft_vsum(t_vec veca, t_vec vecb)
{
	veca.x += vecb.x;
	veca.y += vecb.y;
	veca.z += vecb.z;
	return (veca);
}
