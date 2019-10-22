/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 03:54:45 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/22 18:09:42 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	fill_camera(char **split, t_vec3 *from, t_vec3 *lookat)
{
	char	**str_vec;

	str_vec = ft_strsplit(split[1], ',');
	*from = vec_new(atof(str_vec[0]), atof(str_vec[1]), atof(str_vec[2]));
	str_vec = ft_strsplit(split[2], ',');
	*lookat = vec_new(atof(str_vec[0]), atof(str_vec[1]), atof(str_vec[2]));
	return ;
}

void	fill_light(char **split, t_light *new_light, int *i)
{
	t_light	pars_light;
	char	**str_vec;

	*i -= 1;
	str_vec = ft_strsplit(split[1], ',');
	pars_light.intens = atof(split[2]);
	pars_light.pos = vec_new(atof(str_vec[0]), atof(str_vec[1]), atof(str_vec[2]));
	printf("Light#%d  Pos=%f,%f,%f  Intens=%f\n", *i, pars_light.pos.x, pars_light.pos.y, pars_light.pos.z, pars_light.intens);
	new_light[*i] = light_new(pars_light.pos, pars_light.intens);
	return ;
}

void	fill_sphere(char **split, t_sphere *new_sphere, int *i)
{
	t_sphere	pars_sph;
	char		**str_vec;

	*i -= 1;
	str_vec = ft_strsplit(split[1], ',');
	pars_sph.center = vec_new(atof(str_vec[0]), atof(str_vec[1]), atof(str_vec[2]));
	pars_sph.radius = atof(split[2]);
	pars_sph.blesk = atof(split[3]);
	str_vec = ft_strsplit(split[4], ',');
	pars_sph.color = vec_new(atof(str_vec[0]), atof(str_vec[1]), atof(str_vec[2]));
	printf("Sphere#%d  Centr=%f,%f,%f  Radius=%f", *i, pars_sph.center.x, pars_sph.center.y, pars_sph.center.z, pars_sph.radius);
	printf(" Blesk=%f  Color=%f,%f,%f\n", pars_sph.blesk, pars_sph.color.x, pars_sph.color.y, pars_sph.color.z);
	new_sphere[*i] = sphere_new(pars_sph.center, pars_sph.radius, pars_sph.blesk, pars_sph.color);
	return ;
}

void	fill_plane(char **split, t_plane *new_plane, int *i)
{
	t_plane	pars_pla;
	char	**str_vec;

	*i -= 1;
	str_vec = ft_strsplit(split[1], ',');
	pars_pla.line = vec_new(atof(str_vec[0]), atof(str_vec[1]), atof(str_vec[2]));
	str_vec = ft_strsplit(split[2], ',');
	pars_pla.norm = vec_new(atof(str_vec[0]), atof(str_vec[1]), atof(str_vec[2]));
	//pars_pla.norm = unit_vector(pars_pla.norm);
	pars_pla.blesk = atof(split[3]);
	str_vec = ft_strsplit(split[4], ',');
	pars_pla.color = vec_new(atof(str_vec[0]), atof(str_vec[1]), atof(str_vec[2]));
	printf("Plane#%d  Position=%f,%f,%f  Normal=%f,%f,%f", *i, pars_pla.line.x, pars_pla.line.y, pars_pla.line.z, pars_pla.norm.x, pars_pla.norm.y, pars_pla.norm.z);
	printf(" Blesk=%f  Color=%f,%f,%f\n", pars_pla.blesk, pars_pla.color.x, pars_pla.color.y, pars_pla.color.z);
	new_plane[*i] = plane_new(pars_pla.norm, pars_pla.line, pars_pla.blesk, pars_pla.color);
	return ;
}

void	fill_cone(char **split, t_cone *new_cone, int *i)
{
	t_cone	pars_con;
	char	**str_vec;

	*i -= 1;
	str_vec = ft_strsplit(split[1], ',');
	pars_con.center = vec_new(atof(str_vec[0]), atof(str_vec[1]), atof(str_vec[2]));
	str_vec = ft_strsplit(split[2], ',');
	pars_con.vector = vec_new(atof(str_vec[0]), atof(str_vec[1]), atof(str_vec[2]));
	pars_con.vector = unit_vector(pars_con.vector);
	pars_con.ang = atof(split[3]);
	pars_con.blesk = atof(split[4]);
	str_vec = ft_strsplit(split[5], ',');
	pars_con.color = vec_new(atof(str_vec[0]), atof(str_vec[1]), atof(str_vec[2]));
	printf("Cone#%d  Center=%f,%f,%f  Normal=%f,%f,%f", *i, pars_con.center.x, pars_con.center.y, pars_con.center.z, pars_con.vector.x, pars_con.vector.y, pars_con.vector.z);
	printf("  Ang=%f Blesk=%f  Color=%f,%f,%f\n", pars_con.ang, pars_con.blesk, pars_con.color.x, pars_con.color.y, pars_con.color.z);
	new_cone[*i] = cone_new(pars_con);
	return ;
}

void	fill_cylin(char **split, t_cylin *new_cylinder, int *i)
{
	t_cylin	pars_cyl;
	char	**str_vec;

	*i -= 1;
	str_vec = ft_strsplit(split[1], ',');
	pars_cyl.center = vec_new(atof(str_vec[0]), atof(str_vec[1]), atof(str_vec[2]));
	str_vec = ft_strsplit(split[2], ',');
	pars_cyl.vector = vec_new(atof(str_vec[0]), atof(str_vec[1]), atof(str_vec[2]));
	pars_cyl.vector = unit_vector(pars_cyl.vector);
	str_vec = ft_strsplit(split[5], ',');
	pars_cyl.color = vec_new(atof(str_vec[0]), atof(str_vec[1]), atof(str_vec[2]));
	pars_cyl.blesk = atof(split[4]);
	pars_cyl.radius = atof(split[3]);
	printf("Cylindr#%d  Center=%f,%f,%f  Normal=%f,%f,%f", *i, pars_cyl.center.x, pars_cyl.center.y, pars_cyl.center.z, pars_cyl.vector.x, pars_cyl.vector.y, pars_cyl.vector.z);
	printf("  Radius=%f Blesk=%f  Color=%f,%f,%f\n", pars_cyl.radius, pars_cyl.blesk, pars_cyl.color.x, pars_cyl.color.y, pars_cyl.color.z);
	new_cylinder[*i] = cylin_new(pars_cyl);
	return ;
}
