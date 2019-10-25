/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 20:46:29 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/25 05:41:40 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int			check_blok(t_sdl *sdl, int white_space_cnt)
{
	if (ft_strcmp(STR_AMBIENT, sdl->block_1) == 0)
		if (white_space_cnt != 1)
			return (FALSE);
	if ((ft_strcmp(STR_CAMERA, sdl->block_1) == 0) ||
			(ft_strcmp(STR_LIGHT, sdl->block_1) == 0))
		if (white_space_cnt != 2)
			return (FALSE);
	if ((ft_strcmp(STR_SPHERE, sdl->block_1) == 0) ||
			(ft_strcmp(STR_PLANE, sdl->block_1) == 0))
		if (white_space_cnt != 4)
			return (FALSE);
	if ((ft_strcmp(STR_CONE, sdl->block_1) == 0) ||
			(ft_strcmp(STR_CYLINDR, sdl->block_1) == 0))
		if (white_space_cnt != 5)
			return (FALSE);
	return (TRUE);
}

static int			check_empty(char *path)
{
	int		fd;
	char	*tmp;

	fd = open(path, O_RDONLY);
	if (get_next_line(fd, &tmp) > 0)
	{
		close(fd);
		free(tmp);
		return (FALSE);
	}
	close(fd);
	return (TRUE);
}

static int			check_objs(t_sdl *sdl, char *path)
{
	int		fd;
	char	*tmp;
	char	**split;
	int		white_space_cnt;

	if (check_empty(path))
		return (FALSE);
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &tmp) > 0)
	{
		split = ft_strsplit(tmp, ' ');
		sdl->block_1 = split[0];
		if (!check_blok_1(sdl))
			return (false_free_close_split(&tmp, &fd, &split));
		white_space_cnt = str_count_c(tmp, ' ');
		if (!check_blok(sdl, white_space_cnt))
			return (false_free_close_split(&tmp, &fd, &split));
		init_bloks(sdl, split);
		if (!check_all_block(sdl))
			return (false_free_close_split(&tmp, &fd, &split));
		free_tmp_free_split(&tmp, &split);
	}
	close(fd);
	return (TRUE);
}

int					valid_param(t_sdl *sdl, char *path)
{
	if (!(check_objs(sdl, path)))
		return (FALSE);
	return (TRUE);
}
