/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 10:10:14 by hbruvry           #+#    #+#             */
/*   Updated: 2018/12/17 16:57:10 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RTV1_H
# define __RTV1_H

# include "libft/libft.h"
# include "librt/librt.h"
# include "mlx.h"

/*
** # include "/usr/X11/include/mlx.h"
*/

# define WIDTH	500
# define HEIGHT	500
# define PI 3.14159265359
# define EPSILON 0.0000000001

/*
** This camera structure contain variables
** used to rotate our polar camera around its anchor
*/

typedef struct	s_cam
{
	double		fov;
	t_vec		anchor;
	double		radius;
	double		lon;
	double		lat;
	double		rot[2];
	t_vec		world;
	t_vec		reltv;
	t_vec		polar;
	t_vec		xaxis;
	t_vec		yaxis;
	t_vec		zaxis;
	t_m4b4		ctow;
	t_m4b4		wtoc;
}				t_cam;

/*
** This environment structure contain all variables used by the MiniLibX
** and three lists containing cameras, lights and objects
*/

typedef struct	s_env
{
	char		*file;
	char		*name;
	int			w;
	int			h;
	int			precision;
	void		*mlx;
	void		*win;
	void		*pic;
	int			*stp;
	int			pa;
	int			pb;
	int			pc;
	t_cam		tcam;
	t_list		*lcam;
	t_list		*llight;
	t_list		*lobj;
	t_vec		pos;
}				t_env;

/*
** This light structure contain all variables used to illuminate the scene
*/

typedef struct	s_light
{
	double		lum;
	t_vec		origin;
}				t_lig;

/*
** This object structure contain all variables
** used to interpret and draw objects
*/

typedef struct	s_obj
{
	char		*type;
	double		angle;
	t_vec		scale;
	t_vec		origin;
	t_vec		rot;
	t_vec		dir;
	double		rgb[3];
	t_m3b3		linear_otow;
	t_m3b3		linear_wtoo;
	t_m4b4		otow;
	t_m4b4		wtoo;
	t_m3b3		ntow;
}				t_obj;

/*
** This clo structure contain a cam, a light and an object structure
*/

typedef struct	s_clo
{
	t_cam		cam;
	t_lig		light;
	t_obj		obj;
}				t_clo;

/*
** This ray structure contain origin and direction of a ray
*/

typedef struct	s_ray
{
	t_vec		origin;
	t_vec		dir;
}				t_ray;

/*
** This calculation structure contain all variables used to calculate
** intersection between rays and objects
*/

typedef struct	s_cal
{
	double		radius;
	t_vec		origin;
	t_vec		dir;
	double		alpha;
	double		a;
	double		b;
	double		c;
	double		delta;
	double		t[2];
}				t_cal;

t_env			*ft_getenv(void);
int				ft_setobj(char **fc, t_obj *ao);
int				ft_setenv(char *file);
void			ft_lfill(t_list **alst, void const *c, size_t cs);
char			**ft_filecopy(char *file);
int				ft_filecheck(char *file);
void			ft_putenv(void);
double			ft_intersect(t_env *e, t_ray r, t_obj *ao);
void			ft_drawscene(void);
void			ft_drawtext(void);

#endif
