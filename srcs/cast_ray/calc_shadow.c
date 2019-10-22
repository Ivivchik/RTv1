/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_shadow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 04:30:13 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/22 07:37:33 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		sdl_to_buf(t_sdl *sdl, t_buf_color *buf)
{
	(*buf).ble = sdl->f_blesk;
	(*buf).col = sdl->f_color;
	(*buf).cen = sdl->f_center;
	return ;
}

static void		buf_to_sdl(t_sdl **sdl, t_buf_color buf)
{
	(*sdl)->f_blesk = buf.ble;
	(*sdl)->f_color = buf.col;
	(*sdl)->f_center = buf.cen;
	return ;
}

static t_ray	init_shadow_ray(t_calc_light me, double *check)
{
	t_vec3	dist;
	t_vec3	light_dir;
	t_vec3	shadow_orig;
	t_ray	ray;

	dist = vec_op_sub(me.l.pos, me.p);
	*check = sqrtf(vec_dot(dist, dist));
	dist = unit_vector(dist);
	light_dir = unit_vector(vec_op_sub(me.l.pos, me.p));
	shadow_orig = ((vec_dot(light_dir, me.n) < 0) ?
			vec_op_sub(me.p, vec_scale(me.n, 0.001)) :
			vec_op_add(me.p, vec_scale(me.n, 0.001)));
	ray = new_ray(shadow_orig, dist);
	return (ray);
}

static uint8_t	add_shadow(t_sdl *sdl)
{
	sdl->intens *= 0.7f;
	return (TRUE);
}

uint8_t			calc_shadow(t_calc_light me, t_sdl *sdl)
{
	double		close_t;
	double		*t_sh;
	t_buf_color	buf_col;
	int			i;
	double		check;

	sdl_to_buf(sdl, &buf_col);
	i = -1;
	close_t = MAX_DIST;
	while (++i < sdl->nbrs.num_obj)
	{
		if (!(t_sh = cast_ray_for_obj(sdl, init_shadow_ray(me, &check), i)))
			ft_print_error_exit(&ft_putendl, "Error, no_memalloc_for_t");
		if (t_sh[0] >= MIN_DIST && t_sh[0] <= MAX_DIST && t_sh[0] < close_t)
			close_t = t_sh[0];
		if (t_sh[1] >= MIN_DIST && t_sh[1] <= MAX_DIST && t_sh[1] < close_t)
			close_t = t_sh[1];
		buf_to_sdl(&sdl, buf_col);
		free(t_sh);
		if (close_t < MAX_DIST && close_t < check)
			return (add_shadow(sdl));
	}
	return (FALSE);
}
