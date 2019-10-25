/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_objects_part1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 03:54:45 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/25 03:46:18 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	fill_camera(char **split, t_vec3 *from, t_vec3 *lookat)
{
	char	**s;

	s = ft_strsplit(split[1], ',');
	*from = vec_new(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
	free_split_vec3_true(&s);
	s = ft_strsplit(split[2], ',');
	*lookat = vec_new(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
	free_split_vec3_true(&s);
	return ;
}

void	fill_ambient(char **split, double *amb)
{
	*amb = valid_intens(ft_atof(split[1]));
	return ;
}

void	fill_light(char **split, t_light *new_light, int *i)
{
	t_light	pars_light;
	char	**s;

	*i -= 1;
	s = ft_strsplit(split[1], ',');
	pars_light.intens = valid_intens(ft_atof(split[2]));
	pars_light.pos = vec_new(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
	free_split_vec3_true(&s);
	new_light[*i] = light_new(pars_light.pos, pars_light.intens);
	return ;
}

void	fill_sphere(char **split, t_sphere *new_sphere, int *i)
{
	t_sphere	pars_sph;
	char		**s;

	*i -= 1;
	s = ft_strsplit(split[1], ',');
	pars_sph.center = vec_new(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
	free_split_vec3_true(&s);
	pars_sph.radius = valid_radius(ft_atof(split[2]));
	pars_sph.blesk = valid_blesk(ft_atof(split[3]));
	s = ft_strsplit(split[4], ',');
	pars_sph.color = vec_new(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
	free_split_vec3_true(&s);
	new_sphere[*i] = sphere_new(pars_sph.center,
		pars_sph.radius, pars_sph.blesk, pars_sph.color);
	return ;
}
