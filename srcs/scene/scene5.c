/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 00:05:03 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/21 20:41:14 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_sphere	*exec_sphere_5(void)
{
	t_sphere	*spheres;
	int			nbrs_sph;

	if (!(nbrs_sph = NUMB_SPHERE_IN_SCENE5))
		return (NULL);
	spheres = create_null_list_spheres(nbrs_sph);
	if (!(spheres))
		ft_print_error_exit(&ft_putendl, "Error, no_spheres");
	spheres[0] = sphere_new(vec_new(0, 0, 0), 1, 250, vec_new(255, 0, 0));
	spheres[1] = sphere_new(vec_new(-4, -3, 8), 1, 10, vec_new(250, 250, 250));
	spheres[2] = sphere_new(vec_new(-4, -3, 0), 1, 10, vec_new(250, 250, 250));
	spheres[3] = sphere_new(vec_new(4, -3, 8), 1, 10, vec_new(250, 250, 250));
	spheres[4] = sphere_new(vec_new(4, -3, 0), 1, 10, vec_new(250, 250, 250));
	spheres[5] = sphere_new(vec_new(-4, 5, 8), 1, 10, vec_new(250, 250, 250));
	spheres[6] = sphere_new(vec_new(-4, 5, 0), 1, 10, vec_new(250, 250, 250));
	spheres[7] = sphere_new(vec_new(4, 5, 8), 1, 10, vec_new(250, 250, 250));
	spheres[8] = sphere_new(vec_new(4, 5, 0), 1, 10, vec_new(250, 250, 250));
	return (spheres);
}

t_cone		*exec_cone_5(void)
{
	t_cone	*cone;
	int		nbrs_cone;
	t_vec3	v;

	if (!(nbrs_cone = NUMB_CONE_IN_SCENE5))
		return (NULL);
	cone = create_null_list_cone(nbrs_cone);
	if (!(cone))
		ft_print_error_exit(&ft_putendl, "Error, no_cone");
	v = vec_new(0, 2, 0);
	v = vec_new(v.x / vec_length(v), v.y / vec_length(v), v.z / vec_length(v));
	cone[0] = cone_new(vec_new(0, 0, 2), v, vec_new(255, 0, 255), 0.6);
	return (cone);
}

t_plane		*exec_plane_5(void)
{
	t_plane	*plane;
	int		nbrs_plane;

	if (!(nbrs_plane = NUMB_PLANE_IN_SCENE5))
		return (NULL);
	plane = create_null_list_plane(nbrs_plane);
	if (!(plane))
		ft_print_error_exit(&ft_putendl, "Error, no_plane");
	plane[0] = plane_new(vec_new(0, 1, 0), vec_new(0, -3, -10), 250,
			vec_new(200, 200, 200));
	plane[1] = plane_new(vec_new(0, -1, 0), vec_new(0, 5, -10), 250,
			vec_new(200, 200, 200));
	plane[2] = plane_new(vec_new(0, 0, 1), vec_new(0, 1, 20), 250,
			vec_new(0, 150, 250));
	return (plane);
}

t_cylin		*exec_cylinder_5(void)
{
	t_cylin		*cylin;
	int			nbrs_cylin;
	t_vec3		v;

	if (!(nbrs_cylin = NUMB_CYLINDR_IN_SCENE5))
		return (NULL);
	cylin = create_null_list_cylinder(nbrs_cylin);
	if (!(cylin))
		ft_print_error_exit(&ft_putendl, "Error, no_cylinder");
	v = vec_new(0, 1, 0);
	v = vec_new(v.x / vec_length(v), v.y / vec_length(v), v.z / vec_length(v));
	cylin[0] = cylin_new(vec_new(4, 1, 0), v, 0.6, vec_new(250, 250, 250));
	v = vec_new(0, 1, 0);
	v = vec_new(v.x / vec_length(v), v.y / vec_length(v), v.z / vec_length(v));
	cylin[1] = cylin_new(vec_new(4, 1, 8), v, 0.6, vec_new(250, 250, 250));
	v = vec_new(0, 1, 0);
	v = vec_new(v.x / vec_length(v), v.y / vec_length(v), v.z / vec_length(v));
	cylin[2] = cylin_new(vec_new(-4, 1, 0), v, 0.6, vec_new(250, 250, 250));
	v = vec_new(0, 1, 0);
	v = vec_new(v.x / vec_length(v), v.y / vec_length(v), v.z / vec_length(v));
	cylin[3] = cylin_new(vec_new(-4, 1, 8), v, 0.6, vec_new(250, 250, 250));
	return (cylin);
}

void		scene5(t_sdl **sdl)
{
	SDL_Surface	*frame;
	t_light		*light;
	int			nbr_light;

	frame = create_surface(WIN_WIDTH, WIN_HEIGHT);
	init_obj(&((*sdl)->obj), &((*sdl)->num_obj), SCENE5_IMG);
	nbr_light = NUMB_LIGHTS_IN_SCENE5;
	if (!(light = create_null_list_lights(nbr_light)) && nbr_light)
		ft_print_error_exit(&ft_putendl, "Error, no_alloc_for_light");
	light[0] = light_new(vec_new(-20, 4.99, -10), 0.8);
	//light[0] = light_new(vec_new(25, 4, -10), 0.4);
	(*sdl)->light = light;
	(*sdl)->lookfr = vec_new(0, 0, 30);
	(*sdl)->lookat = vec_op_sub(vec_new(0, 0, 1), (*sdl)->rot_ang);
	draw_scene_main(frame, sdl);
	(*sdl)->image = frame;
	ft_putstr("Loading: scene5\n");
	return ;
}
