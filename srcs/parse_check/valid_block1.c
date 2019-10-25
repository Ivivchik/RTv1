/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_block1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 21:07:35 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/25 02:23:16 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		init_bloks(t_sdl *sdl, char **split)
{
	sdl->block_2 = split[1];
	sdl->block_3 = split[2];
	sdl->block_4 = split[3];
	sdl->block_5 = split[4];
	sdl->block_6 = split[5];
	return ;
}

int			try_find_objs(char *obj_block)
{
	if ((ft_strcmp(STR_CAMERA, obj_block) == 0) ||
			(ft_strcmp(STR_LIGHT, obj_block) == 0) ||
			(ft_strcmp(STR_SPHERE, obj_block)) == 0 ||
			(ft_strcmp(STR_PLANE, obj_block) == 0) ||
			(ft_strcmp(STR_CONE, obj_block) == 0) ||
			(ft_strcmp(STR_AMBIENT, obj_block) == 0) ||
			(ft_strcmp(STR_CYLINDR, obj_block) == 0))
		return (TRUE);
	return (FALSE);
}

int			check_blok_1(t_sdl *sdl)
{
	if (!sdl->block_1 || !try_find_objs(sdl->block_1))
		return (FALSE);
	return (TRUE);
}
