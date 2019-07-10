/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 16:07:35 by hbruvry           #+#    #+#             */
/*   Updated: 2018/11/19 14:51:57 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

/*
** Print coordinates
*/

void	ft_putcoor(char *str, t_vec v)
{
	int	i;

	i = -1;
	ft_putstr("\t");
	ft_putstr(str);
	if (ft_strlen(str) < 8)
		ft_putstr("\t");
	ft_putstr("\t= {");
	ft_putnbr(v.x);
	ft_putstr(", ");
	ft_putnbr(v.y);
	ft_putstr(", ");
	ft_putnbr(v.z);
	ft_putstr("};\n");
	return ;
}

/*
** Print camera
*/

void	ft_putcam(t_cam c)
{
	ft_putstr("\033[31;1mcamera\033[0m\n{\n\tfov\t\t= ");
	ft_putnbr(c.fov);
	ft_putstr(";\n");
	ft_putcoor("anchor", c.anchor);
	ft_putstr("\tradius\t\t= ");
	ft_putnbr(c.radius);
	ft_putstr(";\n\tlongitude\t= ");
	ft_putnbr(c.lon);
	ft_putstr(";\n\tlatitude\t= ");
	ft_putnbr(c.lat);
	ft_putstr(";\n");
	ft_putstr("}\n\n");
	return ;
}

/*
** Print light
*/

void	ft_putlig(t_lig l)
{
	ft_putstr("\033[33;1mlight\033[0m\n{\n\tluminosity\t= ");
	ft_putnbr(l.lum);
	ft_putstr(";\n");
	ft_putcoor("origin", l.origin);
	ft_putstr("}\n\n");
	return ;
}

/*
** Print object
*/

void	ft_putobj(t_obj o)
{
	t_vec rgb;

	rgb.x = o.rgb[0];
	rgb.y = o.rgb[1];
	rgb.z = o.rgb[2];
	ft_putstr("\033[32;1mobject\033[0m\n{\n\ttype\t\t= \"");
	ft_putstr(o.type);
	ft_putstr(";\n");
	ft_putcoor("origin", o.origin);
	ft_putcoor("scale", o.scale);
	ft_putcoor("rotation", ft_vmul(o.rot, 180 / PI));
	ft_putcoor("color", rgb);
	ft_putstr("}\n\n");
	return ;
}

/*
** Print environment
*/

void	ft_putenv(void)
{
	t_env	*e;
	t_list	*lcam;
	t_list	*llight;
	t_list	*lobj;

	e = ft_getenv();
	lcam = e->lcam;
	llight = e->llight;
	lobj = e->lobj;
	while (lcam)
	{
		ft_putcam(*((t_cam*)lcam->content));
		lcam = lcam->next;
	}
	while (llight)
	{
		ft_putlig(*((t_lig*)llight->content));
		llight = llight->next;
	}
	while (lobj)
	{
		ft_putobj(*((t_obj*)lobj->content));
		lobj = lobj->next;
	}
	return ;
}
