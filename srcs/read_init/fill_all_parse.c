/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_all_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 00:52:42 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/25 02:34:50 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			fill_mew(t_all_obj *objs,
		t_sdl *sdl, char **split, t_nbr_all *all_n)
{
	if (ft_strcmp(STR_CAMERA, sdl->block_1) == 0)
		fill_camera(split, &sdl->lookfr, &sdl->lookat);
	else if (ft_strcmp(STR_SPHERE, sdl->block_1) == 0)
		fill_sphere(split, (*objs).new_sphere, &((*all_n).num_sph));
	else if (ft_strcmp(STR_PLANE, sdl->block_1) == 0)
		fill_plane(split, (*objs).new_plane, &((*all_n).num_pla));
	else if (ft_strcmp(STR_CONE, sdl->block_1) == 0)
		fill_cone(split, (*objs).new_cone, &((*all_n).num_con));
	else if (ft_strcmp(STR_CYLINDR, sdl->block_1) == 0)
		fill_cylin(split, (*objs).new_cylinder, &((*all_n).num_cyl));
	else if (ft_strcmp(STR_AMBIENT, sdl->block_1) == 0)
		fill_ambient(split, &sdl->ambient);
	return ;
}

static void		parse_end(t_sdl **sdl, int *fd, t_light ***new_light)
{
	(*sdl)->light = *(*new_light);
	close(*fd);
	return ;
}

static void		parse_end_while_exit(char **line, int *fd, char ***split)
{
	false_free_close_split(line, fd, split);
	exit(1);
	return ;
}

void			fill_all_parse(t_light **new_light,
		t_all_obj *objs, t_sdl *sdl, char *path)
{
	int			fd;
	char		**split;
	char		*line;
	t_nbr_all	all_n;

	all_n = sdl->nbrs;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		split = ft_strsplit(line, ' ');
		sdl->block_1 = split[0];
		if ((ft_strcmp(STR_CAMERA, sdl->block_1) == 0) ||
				(ft_strcmp(STR_SPHERE, sdl->block_1) == 0) ||
				(ft_strcmp(STR_PLANE, sdl->block_1) == 0) ||
				(ft_strcmp(STR_CONE, sdl->block_1) == 0) ||
				(ft_strcmp(STR_AMBIENT, sdl->block_1) == 0) ||
				(ft_strcmp(STR_CYLINDR, sdl->block_1) == 0))
			fill_mew(objs, sdl, split, &all_n);
		else if (ft_strcmp(STR_LIGHT, sdl->block_1) == 0)
			fill_light(split, *new_light, &(all_n.num_lig));
		else
			parse_end_while_exit(&line, &fd, &split);
		free_tmp_free_split(&line, &split);
	}
	parse_end(&sdl, &fd, &new_light);
}
