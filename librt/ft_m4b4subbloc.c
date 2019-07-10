/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m4b4subbloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:17:04 by hbruvry           #+#    #+#             */
/*   Updated: 2018/11/15 16:17:08 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

/*
** Subbloc 4b4 matrice
*/

t_m3b3	ft_m4b4subbloc(t_m4b4 mat, int i, int j)
{
	int		k;
	int		found;
	t_m3b3	subbloc;

	k = -1;
	found = -1;
	if (0 > i || i >= 4 || 0 > j || j >= 4)
	{
		ft_bzero(&subbloc.m, 9 * sizeof(double));
		return (subbloc);
	}
	while (++k < 16)
	{
		if (k / 4 == i)
			k += 3;
		else if (k % 4 != j)
		{
			found++;
			subbloc.m[found % 3][found / 3] = mat.m[k % 4][k / 4];
		}
	}
	return (subbloc);
}
