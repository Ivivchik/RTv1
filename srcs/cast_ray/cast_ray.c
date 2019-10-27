/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 02:20:44 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/27 15:43:38 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		check_color(t_sdl *sdl)
{
	if (sdl->f_color.x < 0 || sdl->f_color.x > 255 ||
		sdl->f_color.y < 0 || sdl->f_color.y > 255 ||
		sdl->f_color.z < 0 || sdl->f_color.z > 255)
		ft_print_error_exit(&ft_putendl, "Error, incorrect color");
}

double		*cast_ray_for_obj(t_sdl *sdl, t_ray ray, int i)
{
	double	*t;

	if (!(t = (double *)malloc(sizeof(double) * 2)))
		return (NULL);
	if (ft_strcmp(sdl->obj[i]->c_type, STR_SPHERE) == 0)
		intersec_sphere(ray, get_sph(sdl->obj[i]->type), sdl, &t);
	else if (ft_strcmp(sdl->obj[i]->c_type, STR_CONE) == 0)
		intersec_conus(ray, get_con(sdl->obj[i]->type), sdl, &t);
	else if (ft_strcmp(sdl->obj[i]->c_type, STR_PLANE) == 0)
		intersec_plane(ray, get_pla(sdl->obj[i]->type), sdl, &t);
	else if (ft_strcmp(sdl->obj[i]->c_type, STR_CYLINDR) == 0)
		intersec_cylinder(ray, get_cyl(sdl->obj[i]->type), sdl, &t);
	return (t);
}

t_vec3		calc_color(double close_t, t_ray ray, t_sdl *sdl, int i)
{
	t_vec3	col_out;
	t_vec3	p;
	t_vec3	n;
	double	max_f;

	n = vec_new(0, 0, 0);
	p = vec_op_add(ray.origin, vec_scale(ray.direct, close_t));
	if (ft_strcmp(sdl->obj[i]->c_type, STR_SPHERE) == 0)
		n = normal_sphere(p, i, sdl);
	else if (ft_strcmp(sdl->obj[i]->c_type, STR_CONE) == 0)
		n = normal_cone(p, i, sdl);
	else if (ft_strcmp(sdl->obj[i]->c_type, STR_PLANE) == 0)
		n = normal_plane(p, i, sdl);
	else if (ft_strcmp(sdl->obj[i]->c_type, STR_CYLINDR) == 0)
	{
		sdl->norm_cylin = ray;
		n = normal_cylinder(p, i, sdl, close_t);
	}
	check_color(sdl);
	col_out = vec_scale(sdl->f_color, computer_lighting(p, n, sdl,
				vec_scale(ray.direct, -1)));
	max_f = fmax(col_out.x, (fmax(col_out.y, col_out.z)));
	col_out = (max_f > 255) ? vec_scale(col_out, 255.0 / max_f) : col_out;
	return (col_out);
}

t_vec3		cast_ray(t_ray ray, t_sdl *sdl)
{
	t_vec3	color;
	int		i;
	double	*t;
	double	close_t;

	i = -1;
	close_t = MAX_DIST;
	color = vec_new(0, 0, 0);
	while (++i < sdl->nbrs.num_obj)
	{
		if (!(t = cast_ray_for_obj(sdl, ray, i)))
			ft_print_error_exit(&ft_putendl, "Error, no_memalloc_for_t");
		if (t[0] >= MIN_DIST && t[0] <= MAX_DIST && t[0] < close_t)
		{
			close_t = t[0];
			color = calc_color(close_t, ray, sdl, i);
		}
		if (t[1] >= MIN_DIST && t[1] <= MAX_DIST && t[1] < close_t)
		{
			close_t = t[1];
			color = calc_color(close_t, ray, sdl, i);
		}
		free(t);
	}
	return (color);
}
