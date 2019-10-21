/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersecray_sphere.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 07:32:22 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/19 08:04:04 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		*intersec_sphere(t_ray ray, t_sphere s, t_sdl *sdl, double **bb)
{
	double	*t;
	t_vec3	v;
	double	r;
	t_vec3	b;

	t = *bb;
	mem_sdl_buf_sph(&sdl, s);
	r = s.radius;
	v = vec_op_sub(ray.origin, s.center);
	b = ray.direct;
	sdl->k1 = vec_dot(b, b);
	sdl->k2 = 2.f * vec_dot(v, b);
	sdl->k3 = vec_dot(v, v) - r * r;
	sdl->dis = sdl->k2 * sdl->k2 - 4.f * sdl->k1 * sdl->k3;
	if (sdl->dis < 0)
	{
		t[0] = MAX_DIST;
		t[1] = MAX_DIST;
		return (t);
	}
	t[0] = (-sdl->k2 + sqrtf(sdl->dis)) / (2.f * sdl->k1);
	t[1] = (-sdl->k2 - sqrtf(sdl->dis)) / (2.f * sdl->k1);
	return (t);
}
