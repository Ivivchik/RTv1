/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 23:20:07 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/25 05:43:31 by gwaymar-         ###   ########.fr       */
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
		ft_print_error_exit(&ft_putendl, "Error, no_light");
	return (light);
}
