/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 14:09:33 by hbruvry           #+#    #+#             */
/*   Updated: 2018/12/19 13:15:44 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

/*
** Set env value according to file copy
*/

int		ft_setscene(char **fc)
{
	int		i;
	t_env	*e;

	i = 0;
	e = ft_getenv();
	e->precision = 1;
	if (ft_strcmp(fc[++i], "{"))
		return (0);
	while (fc[++i] != NULL)
		if (!ft_strncmp(fc[i], "name=", 5))
			e->name = ft_strsub(fc[i], 6, ft_strlen(fc[i]) - 8);
		else if (!ft_strncmp(fc[i], "width=", 6))
			e->w = ft_atoi(fc[i] + 6);
		else if (!ft_strncmp(fc[i], "height=", 7))
			e->h = ft_atoi(fc[i] + 7);
		else if (!ft_strncmp(fc[i], "precision=", 10))
			ft_atoi(fc[i] + 10) > 0 ? e->precision = ft_atoi(fc[i] + 10) : 1;
		else if (!ft_strcmp(fc[i], "}"))
			return (1);
	return (0);
}

/*
** Set camera structure according to file copy
*/

int		ft_setcam(char **fc, t_cam *ac)
{
	int		i;

	i = 0;
	ft_bzero(ac, sizeof(ac));
	ac->lon = 90;
	if (ft_strcmp(fc[++i], "{"))
		return (0);
	while (fc[++i] != NULL)
		if (!ft_strncmp(fc[i], "fov=", 4))
			ac->fov = ft_atoi(fc[i] + 4);
		else if (!ft_strncmp(fc[i], "anchor=", 7))
			ft_vfill(&ac->anchor.x, &ac->anchor.y, &ac->anchor.z, fc[i]);
		else if (!ft_strncmp(fc[i], "radius=", 7))
			ac->radius = ft_atoi(fc[i] + 7);
		else if (!ft_strncmp(fc[i], "longitude=", 10))
			ac->lon = ft_atoi(fc[i] + 10);
		else if (!ft_strncmp(fc[i], "latitude=", 9))
			ac->lat = ft_atoi(fc[i] + 9);
		else if (!ft_strcmp(fc[i], "}"))
		{
			ac->rot[0] = ac->lon;
			ac->rot[1] = ac->lat;
			return (1);
		}
	return (0);
}

/*
** Set light structure according to file copy
*/

int		ft_setlig(char **fc, t_lig *al)
{
	int		i;

	i = 0;
	ft_bzero(al, sizeof(al));
	if (ft_strcmp(fc[++i], "{"))
		return (0);
	while (fc[++i] != NULL)
		if (!ft_strncmp(fc[i], "luminosity=", 11))
			al->lum = ft_atoi(fc[i] + 11);
		else if (!ft_strncmp(fc[i], "origin={", 8))
			ft_vfill(&al->origin.x, &al->origin.y, &al->origin.z, fc[i]);
		else if (!ft_strcmp(fc[i], "}"))
			return (1);
	return (0);
}

/*
** Free file copy
*/

void	ft_freefcpy(char **fcpy)
{
	int		i;

	i = -1;
	while (fcpy[++i] != NULL)
		free(fcpy[i]);
	free(fcpy);
	return ;
}

/*
** Set and fill env lists according to file copy
*/

int		ft_setenv(char *file)
{
	int		i;
	int		r;
	char	**fcpy;
	t_clo	c;
	t_env	*e;

	i = -1;
	r = 1;
	e = ft_getenv();
	if (!(fcpy = ft_filecopy(file)))
		return (0);
	while (fcpy[++i] != NULL && r == 1)
		if (!ft_strcmp(fcpy[i], "scene"))
			!ft_setscene(fcpy + i) ? r = 0 : 0;
		else if (!ft_strcmp(fcpy[i], "camera"))
			!ft_setcam(fcpy + i, &c.cam) ? r = 0
			: ft_lfill(&e->lcam, &c.cam, sizeof(c.cam));
		else if (!ft_strcmp(fcpy[i], "light"))
			!ft_setlig(fcpy + i, &c.light) ? r = 0
			: ft_lfill(&e->llight, &c.light, sizeof(c.light));
		else if (!ft_strcmp(fcpy[i], "object"))
			!ft_setobj(fcpy + i, &c.obj) ? r = 0
			: ft_lfill(&e->lobj, &c.obj, sizeof(c.obj));
	ft_freefcpy(fcpy);
	return (r);
}
