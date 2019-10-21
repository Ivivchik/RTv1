/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 06:29:53 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/21 17:57:57 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_sphere	*exec_sphere_3(void)
{
	return (NULL);
}

t_cone		*exec_cone_3(void)
{
	t_cone	*cone;
	int		nbrs_cone;
	t_vec3	v;

	if (!(nbrs_cone = NUMB_CONE_IN_SCENE3))
		return (NULL);
	cone = create_null_list_cone(nbrs_cone);
	if (!(cone))
		ft_print_error_exit(&ft_putendl, "Error, no_cone");
	v = vec_new(0, 1, 0);
	v = vec_new(v.x / vec_length(v), v.y / vec_length(v), v.z / vec_length(v));
	cone[0] = cone_new(vec_new(0, 0, 0), v, vec_new(255, 0, 255), 0.6);
	return (cone);
}

t_plane		*exec_plane_3(void)
{
	t_plane	*plane;
	int		nbrs_plane;

	if (!(nbrs_plane = NUMB_PLANE_IN_SCENE3))
		return (NULL);
	plane = create_null_list_plane(nbrs_plane);
	if (!(plane))
		ft_print_error_exit(&ft_putendl, "Error, no_plane");
	plane[0] = plane_new(vec_new(0, 1, 0), vec_new(0, -1.8, -4), 250,
			vec_new(0, 200, 0));
	return (plane);
}

t_cylin		*exec_cylinder_3(void)
{
	return (NULL);
}

void		scene3(t_sdl **sdl)
{
	SDL_Surface	*frame;
	t_light		*light;
	int			nbr_light;

	frame = create_surface(WIN_WIDTH, WIN_HEIGHT);
	init_obj(&((*sdl)->obj), &((*sdl)->num_obj), SCENE3_IMG);
	nbr_light = NUMB_LIGHTS_IN_SCENE3;
	if (!(light = create_null_list_lights(nbr_light)) && nbr_light)
		ft_print_error_exit(&ft_putendl, "Error, no_alloc_for_light");
	light[0] = light_new(vec_new(0, 0, -8), 0.4);
	light[1] = light_new(vec_new(20, -1, -8), 0.4);
	(*sdl)->light = light;
	(*sdl)->lookfr = vec_new(0, -1, -4);
	(*sdl)->lookat = vec_op_sub(vec_new(0, 0, 1), (*sdl)->rot_ang);
	draw_scene_main(frame, sdl);
	(*sdl)->image = frame;
	ft_putstr("Loading: scene3\n");
	return ;
}
