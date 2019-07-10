/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 10:03:09 by hbruvry           #+#    #+#             */
/*   Updated: 2018/12/18 14:10:24 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

/*
** Reset scene to black
*/

void	ft_putscene(void)
{
	int		i;
	int		j;
	t_env	*e;

	i = -1;
	e = ft_getenv();
	while (++i < e->h)
	{
		j = -1;
		while (++j < e->w)
			e->stp[(int)(e->h - i) * e->w + j] = 0xFFFFFF;
	}
	ft_drawscene();
	ft_drawtext();
	return ;
}

/*
** Change environment variables according to key pressed
*/

int		ft_hook(int k, t_env *e)
{
	t_cam	cam;

	cam = *((t_cam*)e->lcam->content);
	if (k == 65361 || k == 0 || k == 65362 || k == 2 || k == 65363 || k == 1
		|| k == 65364 || k == 13 || k == 51 || k == 53 || k == 31 || k == 35)
	{
		(k == 65362 || k == 13) && cam.lon > 3 ? cam.lon = cam.lon - 2 : 1;
		k == 65361 || k == 0 ? cam.lat = cam.lat + 2 : 1;
		(k == 65364 || k == 1) && cam.lon < 177 ? cam.lon = cam.lon + 2 : 1;
		k == 65363 || k == 2 ? cam.lat = cam.lat - 2 : 1;
		k == 31 && e->precision > 1 ? e->precision -= e->precision / 2 : 1;
		k == 35 && e->precision < 16 ? e->precision += e->precision * 2 : 1;
		k == 51 ? cam.lon = cam.rot[0] : 1;
		k == 51 ? cam.lat = cam.rot[1] : 1;
		if (k == 53)
		{
			mlx_destroy_window(e->mlx, e->win);
			exit(0);
		}
		*((t_cam*)e->lcam->content) = cam;
		ft_putscene();
		return (1);
	}
	return (0);
}

/*
** Get keyboard control
*/

int		ft_keycontrol(void)
{
	t_env	*e;

	e = ft_getenv();
	if (!mlx_hook(e->win, 2, 5, ft_hook, e))
		return (1);
	return (0);
}

/*
** "Ray tracing is not slow - computers are"
** 	James Kajiya
*/

int		main(int argc, char **argv)
{
	t_env	*e;

	e = ft_getenv();
	if (argc != 2 || !ft_strncmp(argv[1], "/dev/fd", 7))
	{
		ft_putstr("usage: ./rtv1 scene_file\n");
		return (0);
	}
	else
	{
		if (!ft_setenv(argv[1]))
			return (0);
		ft_putenv();
		ft_putstr("move : w/a/s/d\npixelate : o/p\n");
		ft_putstr("reset : delete\nclose : escape\n");
		if (!ft_keycontrol())
			ft_putscene();
		mlx_loop(e->mlx);
	}
	return (0);
}
