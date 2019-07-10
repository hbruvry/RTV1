/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 13:14:08 by hbruvry           #+#    #+#             */
/*   Updated: 2018/12/17 16:16:33 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

/*
** Create or return environment structure
*/

t_env	*ft_getenv(void)
{
	static	t_env	*e = NULL;

	if (e == NULL)
	{
		if (!(e = ft_memalloc(sizeof(t_env))))
			return (NULL);
		e->name = ft_strdup("RTV1");
		e->w = WIDTH;
		e->h = HEIGHT;
		e->mlx = mlx_init();
		e->win = mlx_new_window(e->mlx, e->w, e->h, e->name);
		free(e->name);
		e->pic = mlx_new_image(e->mlx, e->w, e->h);
		e->stp = (int*)mlx_get_data_addr(e->pic, &e->pa, &e->pb, &e->pc);
		e->lcam = NULL;
		e->llight = NULL;
		e->lobj = NULL;
	}
	return (e);
}
