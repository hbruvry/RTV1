/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 11:55:22 by hbruvry           #+#    #+#             */
/*   Updated: 2018/12/17 10:41:49 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LIBRT_H
# define __LIBRT_H

# include <math.h>
# include "../libft/libft.h"

typedef struct		s_vec
{
	double			x;
	double			y;
	double			z;
}					t_vec;

/*
** This is a 3 by 3 matrice
**
** [ 0,0 | 0,1 | 0,2 ]
** [ 1,0 | 1,1 | 1,2 ]
** [ 2,0 | 2,1 | 2,2 ]
*/

typedef struct		s_m3b3
{
	double			m[3][3];
}					t_m3b3;

/*
** This is a 4 by 4 matrice
**
** [ 0,0 | 0,1 | 0,2 | 0,3 ]
** [ 1,0 | 1,1 | 1,2 | 1,3 ]
** [ 2,0 | 2,1 | 2,2 | 2,3 ]
** [ 3,0 | 3,1 | 3,2 | 3,3 ]
*/

typedef struct		s_m4b4
{
	double			m[4][4];
}					t_m4b4;

void				ft_vclr(t_vec *vec);
t_vec				ft_vset(double x, double y, double z);
t_vec				ft_vsum(t_vec veca, t_vec vecb);
t_vec				ft_vsub(t_vec veca, t_vec vecb);
t_vec				ft_vmul(t_vec vec, double o);
t_vec				ft_vdiv(t_vec vec, double o);
double				ft_vdot(t_vec veca, t_vec vecb);
double				ft_vsqrd(t_vec vec);
t_vec				ft_vnorm(t_vec vec);
void				ft_vfill(double *na, double *nb, double *nc, char *line);
t_vec				ft_vpolartocartesian(t_vec vec);
t_vec				ft_vcross(t_vec veca, t_vec vecb);
t_vec				ft_vrotx(t_vec vec, double r);
t_vec				ft_vroty(t_vec vec, double r);
t_vec				ft_vrotz(t_vec vec, double r);
t_vec				ft_vrotxyz(t_vec vec, t_vec r);
t_m3b3				ft_m4b4subbloc(t_m4b4 mat, int i, int j);
double				ft_m3b3det(t_m3b3 mat);
t_m4b4				ft_m4b4trans(t_m4b4 mat);
t_m4b4				ft_m4b4scale(t_m4b4 mat, double s);
t_m4b4				ft_m4b4inv(t_m4b4 mat);
t_vec				ft_vtom4b4(t_vec vec, t_m4b4 mat);
t_m3b3				ft_m3b3set(t_vec veca, t_vec vecb, t_vec vecc);
t_m3b3				ft_m3b3rot(double theta, int axis);
t_m3b3				ft_m3b3rotx(double theta);
t_m3b3				ft_m3b3roty(double theta);
t_m3b3				ft_m3b3rotz(double theta);
t_vec				ft_vtom3b3(t_vec vec, t_m3b3 mat);
t_m3b3				ft_m3b3mul(t_m3b3 mata, t_m3b3 matb);
t_m3b3				ft_m3b3scale(t_m3b3 mat, double s);
t_m3b3				ft_m3b3setdiag(t_vec vec);
t_m3b3				ft_m3b3inv(t_m3b3 mat);
t_m4b4				ft_m4b4set(t_m3b3 bloc, t_vec botvec, t_vec rightvec,
							double ncorner);
void				ft_m3b3print(t_m3b3 mat);
void				ft_vprint(t_vec vec);

#endif
