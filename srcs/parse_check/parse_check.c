/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 22:28:32 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/25 03:03:52 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			error_nbr(t_nbr_all nbrs)
{
	if (nbrs.num_cam != 1)
	{
		ft_putstr("Error no camera\n");
		return (FALSE);
	}
	if (nbrs.num_obj == 0)
	{
		ft_putstr("Error no objects\n");
		return (FALSE);
	}
	if (nbrs.num_amb > 1)
	{
		ft_putstr("Error. Need only one ambient\n");
		return (FALSE);
	}
	return (TRUE);
}

t_nbr_all	count(t_sdl *sdl, t_nbr_all nbrs)
{
	if (ft_strcmp(STR_CAMERA, sdl->block_1) == 0)
		nbrs.num_cam++;
	else if (ft_strcmp(STR_LIGHT, sdl->block_1) == 0)
		nbrs.num_lig++;
	else if (ft_strcmp(STR_SPHERE, sdl->block_1) == 0)
		nbrs.num_sph++;
	else if (ft_strcmp(STR_PLANE, sdl->block_1) == 0)
		nbrs.num_pla++;
	else if (ft_strcmp(STR_CONE, sdl->block_1) == 0)
		nbrs.num_con++;
	else if (ft_strcmp(STR_CYLINDR, sdl->block_1) == 0)
		nbrs.num_cyl++;
	else if (ft_strcmp(STR_AMBIENT, sdl->block_1) == 0)
		nbrs.num_amb++;
	return (nbrs);
}

int			check(t_sdl *sdl)
{
	if (ft_strcmp(STR_CAMERA, sdl->block_1) == 0 ||
		ft_strcmp(STR_LIGHT, sdl->block_1) == 0 ||
		ft_strcmp(STR_SPHERE, sdl->block_1) == 0 ||
		ft_strcmp(STR_PLANE, sdl->block_1) == 0 ||
		ft_strcmp(STR_CONE, sdl->block_1) == 0 ||
		ft_strcmp(STR_AMBIENT, sdl->block_1) == 0 ||
		ft_strcmp(STR_CYLINDR, sdl->block_1) == 0)
		return (TRUE);
	else
		return (FALSE);
}

int			check_n(t_nbr_all nbrs, t_sdl *sdl)
{
	if (!error_nbr(nbrs))
		return (TRUE);
	sdl->nbrs = nbrs;
	return (FALSE);
}

int			parse_check(t_sdl *sdl, char *path)
{
	int			fd;
	char		*line;
	t_nbr_all	nbrs;
	char		**split;

	nbrs = nbr();
	if (!valid_param(sdl, path))
		return (wrong_param_false());
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		split = ft_strsplit(line, ' ');
		sdl->block_1 = split[0];
		if (check(sdl))
			nbrs = count(sdl, nbrs);
		else
			return (false_free_close_split(&line, &fd, &split));
		free_tmp_free_split(&line, &split);
	}
	close(fd);
	nbrs.num_obj = nbrs.num_sph + nbrs.num_pla + nbrs.num_con + nbrs.num_cyl;
	if (check_n(nbrs, sdl))
		return (FALSE);
	return (TRUE);
}
