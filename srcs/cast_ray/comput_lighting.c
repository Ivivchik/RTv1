/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comput_lighting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 03:08:11 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/21 20:11:08 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int		get_light_scene_f(int scene_num)
{
	int		num_light;

	num_light = 0;
	if (scene_num == SCENE1_IMG)
		num_light = NUMB_LIGHTS_IN_SCENE1;
	else if (scene_num == SCENE2_IMG)
		num_light = NUMB_LIGHTS_IN_SCENE2;
	else if (scene_num == SCENE3_IMG)
		num_light = NUMB_LIGHTS_IN_SCENE3;
	else if (scene_num == SCENE4_IMG)
		num_light = NUMB_LIGHTS_IN_SCENE4;
	else if (scene_num == SCENE4_1_IMG)
		num_light = NUMB_LIGHTS_IN_SCENE4;
	else if (scene_num == SCENE4_2_IMG)
		num_light = NUMB_LIGHTS_IN_SCENE4;
	else if (scene_num == SCENE5_IMG)
		num_light = NUMB_LIGHTS_IN_SCENE5;
	else if (scene_num == SCENE5_1_IMG)
		num_light = NUMB_LIGHTS_IN_SCENE5;
	else if (scene_num == SCENE5_2_IMG)
		num_light = NUMB_LIGHTS_IN_SCENE5;
	else
		ft_print_error_exit(&ft_putendl, "Error, no_num_light");
	return (num_light);
}

void			calc_blesk(t_calc_light me, t_sdl *rt)
{
	t_vec3	li;
	t_vec3	r;

	li = unit_vector(vec_op_sub(me.l.pos, me.p));
	rt->n_dot_l = vec_dot(li, me.n);
	if (rt->n_dot_l > 0)
		rt->intens += me.l.intens * rt->n_dot_l / vec_length(li);
	if (rt->f_blesk > 0)
	{
		r = vec_op_sub(vec_scale(me.n, 2.f * vec_dot(me.n, li)), li);
		rt->r_dot_v = vec_dot(r, me.v);
		if (rt->r_dot_v > 0)
			rt->intens += me.l.intens * pow(rt->r_dot_v /
					(vec_length(r) * vec_length(me.v)), rt->f_blesk);
	}
	return ;
}

double			computer_lighting(t_vec3 p, t_vec3 n, t_sdl *rt, t_vec3 v)
{
	t_light			*l;
	t_calc_light	me;
	int				k;

	me.n = n;
	me.p = p;
	me.v = v;
	l = rt->light;
	rt->intens = 0.2;
	k = -1;
	while (++k < get_light_scene_f(rt->scene_num))
	{
		me.l = l[k];
		if (l[k].intens > 0 && l[k].intens <= 1)
		{
			if (calc_shadow(me, rt))
				continue;
			calc_blesk(me, rt);
		}
		else
			ft_print_error_exit(&ft_putendl, "Error, incorrect intens");
	}
	return (rt->intens);
}
