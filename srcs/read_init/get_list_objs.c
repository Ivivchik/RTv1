/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list_objs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 03:26:26 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/25 02:14:11 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void			fill_all(t_obj ***all_obj, t_all_obj objs, int *nmbr)
{
	int		i;

	i = 0;
	if (objs.new_sphere)
		fill_objs_sphere(all_obj, objs.new_sphere, &i, nmbr[0]);
	if (objs.new_cone)
		fill_objs_cone(all_obj, objs.new_cone, &i, nmbr[1]);
	if (objs.new_plane)
		fill_objs_plane(all_obj, objs.new_plane, &i, nmbr[2]);
	if (objs.new_cylinder)
		fill_objs_cylin(all_obj, objs.new_cylinder, &i, nmbr[3]);
	return ;
}

static t_all_obj	init_obj_new(t_sdl *sdl)
{
	t_all_obj	objs;

	objs.new_sphere = exec_sphere_1(sdl);
	objs.new_cone = exec_cone_1(sdl);
	objs.new_plane = exec_plane_1(sdl);
	objs.new_cylinder = exec_cylinder_1(sdl);
	return (objs);
}

static void			init_nmbr_sdl(int **nmbr, t_sdl *sdl)
{
	(*nmbr)[0] = sdl->nbrs.num_sph;
	(*nmbr)[1] = sdl->nbrs.num_con;
	(*nmbr)[2] = sdl->nbrs.num_pla;
	(*nmbr)[3] = sdl->nbrs.num_cyl;
	return ;
}

void				get_list_objs(t_sdl *sdl, char *path)
{
	t_light		*new_light;
	t_all_obj	objs;
	t_obj		**all_obj;
	int			*nmbr;
	int			i;

	new_light = exec_light_1(sdl);
	objs = init_obj_new(sdl);
	if (!(nmbr = (int*)malloc(sizeof(int) * 4)))
		ft_print_error_exit(&ft_putendl, "Error, no_alloc_nbr_obj");
	if (!(all_obj = (t_obj **)malloc(sizeof(t_obj*) * sdl->nbrs.num_obj)))
		ft_print_error_exit(&ft_putendl, "Error, no_obj");
	i = -1;
	while (++i < sdl->nbrs.num_obj)
		if (!(all_obj[i] = (t_obj *)malloc(sizeof(t_obj))))
			ft_print_error_exit(&ft_putendl, "Error, no_obj_elem");
	init_nmbr_sdl(&nmbr, sdl);
	fill_all(&all_obj, objs, nmbr);
	free(nmbr);
	sdl->obj = all_obj;
	fill_all_parse(&new_light, &objs, sdl, path);
}
