/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 00:05:03 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/20 14:50:21 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_sphere		*exec_sphere_1(void)
{
	t_sphere	*spheres;
	int			nbrs_sph;

	if (!(nbrs_sph = NUMB_SPHERE_IN_SCENE1))
		return (NULL);
	spheres = create_null_list_spheres(nbrs_sph);
	if (!(spheres))
		ft_print_error_exit(&ft_putendl, "Error, no_spheres");
	spheres[0] = sphere_new(vec_new(0, 0, 0), 1, 250, vec_new(255, 0, 0));
	return (spheres);
}

t_cone			*exec_cone_1(void)
{
	return (NULL);
}

t_plane			*exec_plane_1(void)
{
	return (NULL);
}

t_cylin			*exec_cylinder_1(void)
{
	return (NULL);
}

void			scene1(t_sdl **sdl)
{
	SDL_Surface	*frame;
	t_light		*light;
	int			nbr_light;

	frame = create_surface(WIN_WIDTH, WIN_HEIGHT);
	init_obj(&((*sdl)->obj), &((*sdl)->num_obj), SCENE1_IMG);
	nbr_light = NUMB_LIGHTS_IN_SCENE1;
	if (!(light = create_null_list_lights(nbr_light)) && nbr_light)
		ft_print_error_exit(&ft_putendl, "Error, no_alloc_for_light");
	light[0] = light_new(vec_new(-20, 0, -6), 0.4);
	light[1] = light_new(vec_new(20, 0, -6), 0.4);
	(*sdl)->light = light;
	(*sdl)->lookfr = vec_new(0, 0, -2);
	(*sdl)->lookat = vec_op_sub(vec_new(0, 0, 1), (*sdl)->rot_ang);
	draw_scene_main(frame, sdl);
	(*sdl)->image = frame;
	ft_putstr("Loading: scene1\n");
	return ;
}
