/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawscene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 14:24:13 by hbruvry           #+#    #+#             */
/*   Updated: 2018/12/18 12:21:31 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

/*
** Put a pixel on the screen occording to light luminosity and object color
*/

void	ft_putpixel(double rgb[3], double l, int i, int j)
{
	t_env	*e;
	int		x;
	int		y;

	y = -1;
	e = ft_getenv();
	l >= 255 ? l = 255 : 0;
	l <= 0 ? l = 0 : 0;
	while (++y < e->precision && i + y < HEIGHT)
	{
		x = -1;
		while (++x < e->precision && j + x < WIDTH)
			e->stp[(int)(e->h - i - y) * e->w + j + x] =
			(int)((rgb[0] / 255) * l) * 0x10000
			+ (int)((rgb[1] / 255) * l) * 0x100
			+ (int)((rgb[2] / 255) * l) * 0x1;
	}
	return ;
}

/*
** Camera initialisation
**
** printf("c->anchor = [%f, %f, %f];\n", c->anchor.x, c->anchor.y, c->anchor.z);
** printf("c->polar = [%f, %f, %f];\n", c->polar.x, c->polar.y, c->polar.z);
** printf("c->reltv = [%f, %f, %f];\n", c->reltv.x, c->reltv.y, c->reltv.z);
** printf("c->world = [%f, %f, %f];\n", c->world.x, c->world.y, c->world.z);
** printf("c->xaxis = [%f, %f, %f];\n", c->xaxis.x, c->xaxis.y, c->xaxis.z);
** printf("c->yaxis = [%f, %f, %f];\n", c->yaxis.x, c->yaxis.y, c->yaxis.z);
** printf("c->zaxis = [%f, %f, %f];\n", c->zaxis.x, c->zaxis.y, c->zaxis.z);
*/

void	ft_initcamera(t_cam *c)
{
	t_vec	taxis;

	c->polar = ft_vset(c->radius, c->lon * (PI / 180), c->lat * (PI / 180));
	c->reltv = ft_vpolartocartesian(c->polar);
	c->world = ft_vsum(c->reltv, c->anchor);
	c->zaxis = ft_vnorm(c->reltv);
	taxis = ft_vset(0, 1, 0);
	c->xaxis = ft_vnorm(ft_vcross(taxis, c->zaxis));
	c->yaxis = ft_vcross(c->xaxis, c->zaxis);
	c->ctow = ft_m4b4set(ft_m3b3set(c->xaxis, c->yaxis, c->zaxis),
	ft_vset(0, 0, 0), c->world, 1);
	c->wtoc = ft_m4b4inv(c->ctow);
	return ;
}

/*
** Cast all rays from world to object and illuminate scene
*/

void	ft_raytrace(t_ray pray, t_clo clo, int i, int j)
{
	double	t;
	double	l;
	t_obj	tobj;
	t_ray	sray;
	t_env	*e;

	l = 0;
	e = ft_getenv();
	pray.dir = ft_vnorm(ft_vtom4b4(pray.dir, clo.cam.ctow));
	t = ft_intersect(e, pray, &clo.obj);
	if (EPSILON < t && t != INFINITY)
	{
		sray.origin = ft_vsum(pray.origin, ft_vmul(pray.dir, t));
		sray.dir = ft_vnorm(ft_vsub(pray.origin, clo.obj.origin));
		l = ft_vdot(ft_vnorm(ft_vsub(clo.light.origin, sray.origin)), sray.dir)
		/ ft_vsqrd(ft_vsub(clo.light.origin, sray.origin)) * clo.light.lum;
		sray.dir = ft_vnorm(ft_vsub(clo.light.origin, sray.origin));
		sray.origin = ft_vsum(sray.origin, ft_vmul(sray.dir, EPSILON));
		tobj = clo.obj;
		t = ft_intersect(e, sray, &clo.obj);
		EPSILON < t && pow(t, 2)
		< ft_vsqrd(ft_vsub(clo.light.origin, sray.origin)) ? l = 0 : 1;
		ft_putpixel(tobj.rgb, l, i, j);
	}
	return ;
}

/*
** Light and shadow the 3D scene using raytracing
**
** 	ft_putmat4b4(clo.c.ctow);
** 	ft_putmat4b4(clo.c.wtoc);
**
** 	i < e->h && j < e->w ? ft_lightscene(r, clo, i, j) : 0;
*/

void	ft_drawscene(void)
{
	int		i;
	int		j;
	t_ray	ray;
	t_clo	clo;
	t_env	*e;

	i = -1;
	e = ft_getenv();
	clo.cam = *((t_cam*)e->lcam->content);
	clo.light = *((t_lig*)e->llight->content);
	clo.obj = *((t_obj*)e->lobj->content);
	ft_initcamera(&clo.cam);
	ray.origin = ft_vset(clo.cam.world.x, clo.cam.world.y, clo.cam.world.z);
	while (++i < e->h)
	{
		j = -1;
		while (++j < e->w)
		{
			ray.dir = ft_vset(j - e->w / 2, i - e->h / 2,
				-e->w / (2 * tan(clo.cam.fov / 2)));
			if (i % e->precision == 0 && j % e->precision == 0)
				i < e->h && j < e->w ? ft_raytrace(ray, clo, i, j) : 0;
		}
	}
	mlx_put_image_to_window(e->mlx, e->win, e->pic, 0, 0);
}
