/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 00:06:25 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/21 20:13:20 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_sphere	*exec_sphere_2(void)
{
	return (NULL);
}

t_cone		*exec_cone_2(void)
{
	return (NULL);
}

t_plane		*exec_plane_2(void)
{
	return (NULL);
}

t_cylin		*exec_cylinder_2(void)
{
	t_cylin		*cylin;
	int			nbrs_cylin;
	t_vec3		v;

	if (!(nbrs_cylin = NUMB_CYLINDR_IN_SCENE2))
		return (NULL);
	cylin = create_null_list_cylinder(nbrs_cylin);
	if (!(cylin))
		ft_print_error_exit(&ft_putendl, "Error, no_cylinder");
	v = vec_new(0, 1, 0);
	v = vec_new(v.x / vec_length(v), v.y / vec_length(v), v.z / vec_length(v));
	cylin[0] = cylin_new(vec_new(0, 0, 0), v, 0.6, vec_new(255, 255, 0));
	return (cylin);
}

void		scene2(t_sdl **sdl)
{
	SDL_Surface	*frame;
	t_light		*light;
	int			nbr_light;

	frame = create_surface(WIN_WIDTH, WIN_HEIGHT);
	init_obj(&((*sdl)->obj), &((*sdl)->num_obj), SCENE2_IMG);
	nbr_light = NUMB_LIGHTS_IN_SCENE2;
	if (!(light = create_null_list_lights(nbr_light)) && nbr_light)
		ft_print_error_exit(&ft_putendl, "Error, no_alloc_for_light");
	light[0] = light_new(vec_new(-20, -1, -8), 1);
	light[1] = light_new(vec_new(20, -1, -8), 0.4);
	(*sdl)->light = light;
	(*sdl)->lookfr = vec_new(0, 0, -8);
	(*sdl)->lookat = vec_op_sub(vec_new(0, 0, 1), (*sdl)->rot_ang);
	draw_scene_main(frame, sdl);
	(*sdl)->image = frame;
	ft_putstr("Loading: scene2\n");
	return ;
}
