/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersecray_conus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:58:31 by hkuhic            #+#    #+#             */
/*   Updated: 2019/10/25 05:52:18 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static double	*con_t(double *t, double k2, double dis, double k1)
{
	t[0] = (double)(-k2 + sqrt(dis)) / (2 * k1);
	t[1] = (double)(-k2 - sqrt(dis)) / (2 * k1);
	return (t);
}

static double	*con_t_max(double *t)
{
	t[0] = 0;
	t[1] = 0;
	return (t);
}

double			*intersec_conus(t_ray ray, t_cone s, t_sdl *sdl, double **bb)
{
	double	*t;
	t_vec3	v;
	t_vec3	x;
	double	k;
	t_vec3	b;

	t = *bb;
	mem_sdl_buf_con(&sdl, s);
	v = s.vector;
	k = s.ang;
	x = vec_op_sub(ray.origin, s.center);
	b = ray.direct;
	sdl->k1 = vec_dot(b, b) - (1 + k * k) * vec_dot(b, v) * vec_dot(b, v);
	sdl->k2 = 2 * (vec_dot(b, x) - (1 + k * k) * vec_dot(b, v) * vec_dot(x, v));
	sdl->k3 = vec_dot(x, x) - (1 + k * k) * vec_dot(x, v) * vec_dot(x, v);
	sdl->dis = sdl->k2 * sdl->k2 - 4 * sdl->k1 * sdl->k3;
	return ((sdl->dis < 0) ? con_t_max(t) :
			con_t(t, sdl->k2, sdl->dis, sdl->k1));
}
