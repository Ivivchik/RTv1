/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list_objs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 03:26:26 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/22 18:18:18 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_sphere		*exec_sphere_1(t_sdl *sdl)
{
	t_sphere	*spheres;
	int			nbrs_sph;

	if (!(nbrs_sph = sdl->nbrs.num_sph))
		return (NULL);
	spheres = create_null_list_spheres(nbrs_sph);
	if (!(spheres))
		ft_print_error_exit(&ft_putendl, "Error, no_spheres");
	return (spheres);
}

t_cone			*exec_cone_1(t_sdl *sdl)
{
	t_cone	*cone;
	int		nbrs_cone;

	if (!(nbrs_cone = sdl->nbrs.num_con))
		return (NULL);
	cone = create_null_list_cone(nbrs_cone);
	if (!(cone))
		ft_print_error_exit(&ft_putendl, "Error, no_cone");
	return (cone);
}

t_plane			*exec_plane_1(t_sdl *sdl)
{
	t_plane	*plane;
	int		nbrs_plane;

	if (!(nbrs_plane = sdl->nbrs.num_pla))
		return (NULL);
	plane = create_null_list_plane(nbrs_plane);
	if (!(plane))
		ft_print_error_exit(&ft_putendl, "Error, no_plane");
	return (plane);
}

t_cylin			*exec_cylinder_1(t_sdl *sdl)
{
	t_cylin		*cylin;
	int			nbrs_cylin;
	t_vec3		v;

	if (!(nbrs_cylin = sdl->nbrs.num_cyl))
		return (NULL);
	cylin = create_null_list_cylinder(nbrs_cylin);
	if (!(cylin))
		ft_print_error_exit(&ft_putendl, "Error, no_cylinder");
	return (cylin);
}

t_light			*exec_light_1(t_sdl *sdl)
{
	t_light		*light;
	int			nbrs_light;

	if (!(nbrs_light = sdl->nbrs.num_lig))
		return (NULL);
	light = create_null_list_lights(nbrs_light);
	if (!(light))
		ft_print_error_exit(&ft_putendl, "Error, ni_light");
	return (light);
}

static void		fill_all(t_obj ***all_obj, t_all_obj objs, int *nmbr)
{
	int	i;

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

void			get_list_objs(t_sdl *sdl, char *path)
{
	//init_obj(&(sdl->obj), &(sdl->num_obj), *sdl);
	int			fd;
	char		*line;
	t_sphere	*new_sphere;
	t_cone		*new_cone;
	t_plane		*new_plane;
	t_cylin		*new_cylinder;
	t_light		*new_light;
	int			nbr_light;
	char		**split;
	t_nbr_all	all_n;

	nbr_light = sdl->nbrs.num_lig;
	printf("____________exec_NULL_LIST___________\n");
	printf("SDL_NBRS cam=%d sphere=%d plane=%d\n", sdl->nbrs.num_cam, sdl->nbrs.num_sph, sdl->nbrs.num_pla);
	printf("SDL_NBRS con=%d cylindr=%d light=%d\n", sdl->nbrs.num_con, sdl->nbrs.num_cyl, sdl->nbrs.num_lig);
	printf("SDL_ALL=%d\n", sdl->nbrs.num_obj);
	new_sphere = exec_sphere_1(sdl);
	new_cone = exec_cone_1(sdl);
	new_plane = exec_plane_1(sdl);
	new_cylinder = exec_cylinder_1(sdl);
	new_light = exec_light_1(sdl);

	t_all_obj	objs;

	objs.new_sphere = new_sphere;
	objs.new_cone = new_cone;
	objs.new_plane = new_plane;
	objs.new_cylinder = new_cylinder;

	int			*nmbr;
	if (!(nmbr = (int*)malloc(sizeof(int) * 4)))
		ft_print_error_exit(&ft_putendl, "Error, no_alloc_nbr_obj");

	int num = sdl->nbrs.num_obj;
	t_obj		**all_obj;
	int			i;

	if (!(all_obj = (t_obj **)malloc(sizeof(t_obj*) * num)))
		ft_print_error_exit(&ft_putendl, "Error, no_obj");
	i = -1;
	while (++i < num)
	{
		if (!(all_obj[i] = (t_obj *)malloc(sizeof(t_obj))))
			ft_print_error_exit(&ft_putendl, "Error, no_obj_elem");
	}

	nmbr[0] = sdl->nbrs.num_sph;
	nmbr[1] = sdl->nbrs.num_con;
	nmbr[2] = sdl->nbrs.num_pla;
	nmbr[3] = sdl->nbrs.num_cyl;
	fill_all(&all_obj, objs, nmbr);

	sdl->obj = all_obj;
	if (!(new_light = create_null_list_lights(nbr_light)) && nbr_light)
		ft_print_error_exit(&ft_putendl, "Error, no_alloc_for_light");
	all_n = sdl->nbrs;
	fd = open(path, O_RDONLY);
	printf("____________===___________\n");
	printf("__________filling_____________\n");
	while (get_next_line(fd, &line) > 0)
	{
		split = ft_strsplit(line, ' ');
		sdl->block_1 = split[0];
		if (ft_strcmp(STR_CAMERA, sdl->block_1) == 0)
			fill_camera(split, &sdl->lookfr, &sdl->lookat);
		else if (ft_strcmp(STR_LIGHT, sdl->block_1) == 0)
			fill_light(split, new_light, &(all_n.num_lig));
		else if (ft_strcmp(STR_SPHERE, sdl->block_1) == 0)
			fill_sphere(split, new_sphere, &(all_n.num_sph));
		else if (ft_strcmp(STR_PLANE, sdl->block_1) == 0)
			fill_plane(split, new_plane, &(all_n.num_pla));
		else if (ft_strcmp(STR_CONE, sdl->block_1) == 0)
			fill_cone(split, new_cone, &(all_n.num_con));
		else if (ft_strcmp(STR_CYLINDR, sdl->block_1) == 0)
			fill_cylin(split, new_cylinder, &(all_n.num_cyl));
		else
		{
			printf("error oops second\n");
			close(fd);
			free(line);
			exit(1);
			return ;
		}
		free(line);
	}
	sdl->light = new_light;
	close(fd);
}
