/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:38:20 by hbruvry           #+#    #+#             */
/*   Updated: 2018/11/16 18:04:48 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

/*
** Print vector
*/

/*
** 	ft_putchar('[');
** 	ft_putnbr(vec.x);
** 	ft_putstr(", ");
** 	ft_putnbr(vec.y);
** 	ft_putstr(", ");
** 	ft_putnbr(vec.z);
** 	ft_putstr("]\n");
*/

void	ft_vprint(t_vec vec)
{
	printf("[%f, %f, %f]\n", vec.x, vec.y, vec.z);
	return ;
}
