/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersecray_conus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:58:31 by hkuhic            #+#    #+#             */
/*   Updated: 2019/10/13 22:41:57 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		*intersec_conus(t_vec3 a, t_vec3 b, t_cone s, t_sdl *sdl)
{
	double	*t;
	t_vec3	c;
	t_vec3	v;
	t_vec3 x;
	double	k;

	if (!(t = (double *)malloc(sizeof(double *) * 3)))
		return (0);
	sdl->f_center = s.center;
	sdl->f_blesk = s.blesk;
	sdl->f_color = s.color;
	sdl->k = s.ang;
	sdl->norm_cone = s.vector;
	c = s.center;
	v = s.vector;
	k =	s.ang;
	x = vec_new(a.x - c.x, a.y - c.y, a.z - c.z);
	sdl->x = x;
	sdl->k1 = vec_dot(b, b) - (1 + k * k) * vec_dot(b, v) * vec_dot(b, v);
	sdl->k2 = 2 * (vec_dot(b, x) - (1 + k * k) * vec_dot(b, v) * vec_dot(x, v));
	sdl->k3 = vec_dot(x, x) - (1 + k * k) * vec_dot(x, v) * vec_dot(x, v);
	sdl->dis = sdl->k2 * sdl->k2 - 4 * sdl->k1 * sdl->k3;
	if (sdl->dis < 0)
	{
		t[0] = MAX_DIST;
		t[1] = MAX_DIST;
		t[2] = '\0';
		return (t);
	}
	t[0] = (-sdl->k2 + sqrt(sdl->dis)) / (2 * sdl->k1);
	t[1] = (-sdl->k2 - sqrt(sdl->dis)) / (2 * sdl->k1);
	t[2] = '\0';
	return (t);
}