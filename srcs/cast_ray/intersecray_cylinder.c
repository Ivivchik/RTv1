/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersecray_cylinder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:50:15 by hkuhic            #+#    #+#             */
/*   Updated: 2019/10/21 18:27:01 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static double	*cyl_t(double *t, double k2, double dis, double k1)
{
	t[0] = (-k2 + sqrt(dis)) / (2 * k1);
	t[1] = (-k2 - sqrt(dis)) / (2 * k1);
	return (t);
}

static double	*cyl_t_max(double *t)
{
	t[0] = MAX_DIST;
	t[1] = MAX_DIST;
	return (t);
}

double			*intersec_cylinder(t_ray ray, t_cylin s, t_sdl *sdl,
														double **bb)
{
	double	*t;
	t_vec3	v;
	t_vec3	x;
	double	r;
	t_vec3	b;

	t = *bb;
	mem_sdl_buf_cyl(&sdl, s);
	v = s.vector;
	r = s.radius;
	x = vec_op_sub(ray.origin, s.center);
	b = ray.direct;
	sdl->k1 = vec_dot(b, b) - vec_dot(b, v) * vec_dot(b, v);
	sdl->k2 = 2 * (vec_dot(b, x) - vec_dot(b, v) * vec_dot(x, v));
	sdl->k3 = vec_dot(x, x) - vec_dot(x, v) * vec_dot(x, v) - r * r;
	sdl->dis = sdl->k2 * sdl->k2 - 4 * sdl->k1 * sdl->k3;
	return ((sdl->dis < 0) ? cyl_t_max(t) :
			cyl_t(t, sdl->k2, sdl->dis, sdl->k1));
}
