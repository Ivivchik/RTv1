/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 03:19:39 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/19 02:47:05 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_ray			new_ray(t_vec3 orig, t_vec3 dir)
{
	t_ray	n_ray;

	n_ray.origin = orig;
	n_ray.direct = dir;
	return (n_ray);
}

static t_vec3	get_dir(t_vec3 camera_position, t_vec3 d, double px, double py)
{
	t_vec3	dir_out;
	t_vec3	k;
	t_vec3	i;
	t_vec3	j;

	k = vec_op_sub(d, camera_position);
	k = unit_vector(k);
	i = vec_cross(k, vec_new(0.0, 1.0, 0.0));
	i = unit_vector(i);
	j = vec_cross(i, k);
	dir_out = vec_new(px * i.x + py * j.x + X_LINZE * k.x,
								px * i.y + py * j.y + X_LINZE * k.y,
								px * i.z + py * j.z + X_LINZE * k.z);
	dir_out = unit_vector(dir_out);
	return (dir_out);
}

t_ray			get_camera_ray(t_sdl *sdl, SDL_Surface *surf, int x, int y)
{
	t_ray		cam_ray_out;
	double		imageaspectratio;
	double		px;
	double		py;
	t_vec3		dir;

	imageaspectratio = (double)surf->w / (double)surf->h;
	px = -(2 * ((x + 0.5) / surf->w) - 1) * 2 * imageaspectratio;
	py = (1 - 2 * ((y + 0.5) / surf->h)) * 2;
	dir = sdl->lookat;
	dir = get_dir(sdl->lookfr, dir, px, py);
	cam_ray_out = new_ray(sdl->lookfr, dir);
	return (cam_ray_out);
}
