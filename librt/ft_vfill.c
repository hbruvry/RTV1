/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 15:34:48 by hbruvry           #+#    #+#             */
/*   Updated: 2018/10/02 15:43:01 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"
#include "../libft/libft.h"

/*
** Fill each dimensions of a 3b3 vector according to na, nb, bc
*/

void	ft_vfill(double *na, double *nb, double *nc, char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '{')
		i++;
	i++;
	*na = ft_atoi(line + i);
	while (ft_isdigit(line[i]) || line[i] == '-')
		i++;
	i++;
	*nb = ft_atoi(line + i);
	while (ft_isdigit(line[i]) || line[i] == '-')
		i++;
	i++;
	*nc = ft_atoi(line + i);
	return ;
}
