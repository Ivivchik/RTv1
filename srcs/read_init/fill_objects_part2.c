/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_objects_part2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 03:54:45 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/25 03:45:36 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	fill_plane(char **split, t_plane *new_plane, int *i)
{
	t_plane	pars_pla;
	char	**s;

	*i -= 1;
	s = ft_strsplit(split[1], ',');
	pars_pla.line = vec_new(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
	free_split_vec3_true(&s);
	s = ft_strsplit(split[2], ',');
	pars_pla.norm = vec_new(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
	free_split_vec3_true(&s);
	pars_pla.blesk = valid_blesk(ft_atof(split[3]));
	s = ft_strsplit(split[4], ',');
	pars_pla.color = vec_new(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
	free_split_vec3_true(&s);
	new_plane[*i] = plane_new(pars_pla.norm,
		pars_pla.line, pars_pla.blesk, pars_pla.color);
	return ;
}

void	fill_cone(char **split, t_cone *new_cone, int *i)
{
	t_cone	pars_con;
	char	**s;

	*i -= 1;
	s = ft_strsplit(split[1], ',');
	pars_con.center = vec_new(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
	free_split_vec3_true(&s);
	s = ft_strsplit(split[2], ',');
	pars_con.vector = vec_new(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
	free_split_vec3_true(&s);
	pars_con.vector = unit_vector(pars_con.vector);
	pars_con.ang = ft_atof(split[3]);
	pars_con.blesk = valid_blesk(ft_atof(split[4]));
	s = ft_strsplit(split[5], ',');
	pars_con.color = vec_new(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
	free_split_vec3_true(&s);
	new_cone[*i] = cone_new(pars_con);
	return ;
}

void	fill_cylin(char **split, t_cylin *new_cylinder, int *i)
{
	t_cylin	pars_cyl;
	char	**s;

	*i -= 1;
	s = ft_strsplit(split[1], ',');
	pars_cyl.center = vec_new(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
	free_split_vec3_true(&s);
	s = ft_strsplit(split[2], ',');
	pars_cyl.vector = vec_new(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
	free_split_vec3_true(&s);
	pars_cyl.vector = unit_vector(pars_cyl.vector);
	s = ft_strsplit(split[5], ',');
	pars_cyl.color = vec_new(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
	free_split_vec3_true(&s);
	pars_cyl.blesk = valid_blesk(ft_atof(split[4]));
	pars_cyl.radius = valid_radius(ft_atof(split[3]));
	new_cylinder[*i] = cylin_new(pars_cyl);
	return ;
}
