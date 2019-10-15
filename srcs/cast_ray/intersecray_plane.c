/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersecray_plane.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:01:27 by hkuhic            #+#    #+#             */
/*   Updated: 2019/10/15 21:59:55 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		intersec_plane(t_vec3 a, t_vec3 b, t_plane s, t_sdl *sdl)
{
	double	t;
	t_vec3	c;
	t_vec3	v;
	t_vec3	x;
	double		k;

	sdl->f_blesk = s.blesk;
	sdl->f_color = s.color;
	sdl->f_center = s.norm;
	c = s.line;
	v = s.norm;
	x = vec_new(a.x - c.x, a.y - c.y, a.z - c.z);
	if (vec_dot(b, v) == 0)
		return (0);
	t = - vec_dot(x, v) / vec_dot(b, v);
	return (t);
}