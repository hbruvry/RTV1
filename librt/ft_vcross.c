/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vcross.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:40:36 by hbruvry           #+#    #+#             */
/*   Updated: 2018/11/15 18:01:52 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

/*
** Cross product two 3b3 vectors
*/

t_vec	ft_vcross(t_vec veca, t_vec vecb)
{
	t_vec	tvec;

	tvec.x = veca.y * vecb.z - veca.z * vecb.y;
	tvec.y = veca.z * vecb.x - veca.x * vecb.z;
	tvec.z = veca.x * vecb.y - veca.y * vecb.x;
	return (tvec);
}
