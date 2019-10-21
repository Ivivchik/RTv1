/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene5_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 12:11:32 by hkuhic            #+#    #+#             */
/*   Updated: 2019/10/20 14:33:33 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		scene5_2(t_sdl **sdl)
{
	SDL_Surface	*frame;
	t_light		*light;
	int			nbr_light;

	frame = create_surface(WIN_WIDTH, WIN_HEIGHT);
	init_obj(&((*sdl)->obj), &((*sdl)->num_obj), SCENE5_2_IMG);
	nbr_light = NUMB_LIGHTS_IN_SCENE5;
	if (!(light = create_null_list_lights(nbr_light)) && nbr_light)
		ft_print_error_exit(&ft_putendl, "Error, no_alloc_for_light");
	light[0] = light_new(vec_new(-20, 0, -4), 0.4);
	light[1] = light_new(vec_new(20, 0, -4), 0.4);
	(*sdl)->light = light;
	(*sdl)->lookfr = vec_new(7, 2, 3);
	(*sdl)->lookat = vec_op_sub(vec_new(0, 0, 1), (*sdl)->rot_ang);
	draw_scene_main(frame, sdl);
	(*sdl)->image = frame;
	ft_putstr("Loading: scene5_2\n");
	return ;
}
