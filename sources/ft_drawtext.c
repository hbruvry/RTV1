/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawtext.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 08:05:40 by hbruvry           #+#    #+#             */
/*   Updated: 2018/12/17 10:21:06 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

void	ft_drawnbr(char *str, int x, int y)
{
	int		col;
	t_env	*e;

	col = 0x323232;
	e = ft_getenv();
	mlx_string_put(e->mlx, e->win, x, y, col, str);
	free(str);
}

void	ft_drawtext(void)
{
	int		col;
	t_env	*e;
	t_list	*lcam;
	t_cam	cam;

	col = 0x323232;
	e = ft_getenv();
	lcam = e->lcam;
	cam = *((t_cam*)lcam->content);
	mlx_string_put(e->mlx, e->win, 25, 25, col, "RTV1 - allallem & hbruvry");
	mlx_string_put(e->mlx, e->win, WIDTH - 140, HEIGHT - 101, col, "lon =");
	ft_drawnbr(ft_itoa(cam.lon), WIDTH - 70, HEIGHT - 101);
	mlx_string_put(e->mlx, e->win, WIDTH - 140, HEIGHT - 84, col, "lat =");
	ft_drawnbr(ft_itoa(cam.lat), WIDTH - 70, HEIGHT - 84);
	mlx_string_put(e->mlx, e->win, WIDTH - 140, HEIGHT - 67, col, "fov =");
	ft_drawnbr(ft_itoa(cam.fov), WIDTH - 70, HEIGHT - 67);
	mlx_string_put(e->mlx, e->win, WIDTH - 140, HEIGHT - 50, col, "pix =");
	ft_drawnbr(ft_itoa(e->precision), WIDTH - 70, HEIGHT - 50);
}
