/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersecray_sphere.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 07:32:22 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/13 20:25:57 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		*intersec_sphere(t_vec3 a, t_vec3 b, t_sphere s, t_sdl *sdl)
{
	double	*t;
	t_vec3	c;
	t_vec3	v;
	int		r;

	if (!(t = (double *)malloc(sizeof(double) * 3)))
		return (0);
	sdl->f_center = s.center;
	sdl->f_blesk = s.blesk;
	sdl->f_color = s.color;
	c = s.center;
	r = s.radius;
	v = vec_new(a.x - c.x, a.y - c.y, a.z - c.z);
	sdl->k1 = vec_dot(b, b);
	sdl->k2 = 2 * vec_dot(v, b);
	sdl->k3 = vec_dot(v, v) - r * r;
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
