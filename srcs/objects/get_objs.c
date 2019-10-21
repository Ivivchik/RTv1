/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_objs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 11:15:08 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/19 08:12:26 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_sphere	get_sph(void *sdl_s)
{
	t_sphere	sphere;

	if (sdl_s)
		ft_memcpy(&sphere, sdl_s, sizeof(t_sphere));
	else
		ft_bzero(&sphere, sizeof(t_sphere));
	return (sphere);
}

t_plane		get_pla(void *sdl_p)
{
	t_plane		plane;

	if (sdl_p)
		ft_memcpy(&plane, sdl_p, sizeof(t_plane));
	else
		ft_bzero(&plane, sizeof(t_plane));
	return (plane);
}

t_cone		get_con(void *sdl_o)
{
	t_cone		cone;

	if (sdl_o)
		ft_memcpy(&cone, sdl_o, sizeof(t_cone));
	else
		ft_bzero(&cone, sizeof(t_cone));
	return (cone);
}

t_cylin		get_cyl(void *sdl_c)
{
	t_cylin		cylinder;

	if (sdl_c)
		ft_memcpy(&cylinder, sdl_c, sizeof(t_cylin));
	else
		ft_bzero(&cylinder, sizeof(t_cylin));
	return (cylinder);
}
