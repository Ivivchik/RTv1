/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all_block.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 21:48:27 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/25 02:55:45 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			check_all_block(t_sdl *sdl)
{
	if (!check_blok_2(sdl))
		return (FALSE);
	if (ft_strcmp(STR_AMBIENT, sdl->block_1) != 0)
	{
		if (!check_blok_3(sdl))
			return (FALSE);
		if ((ft_strcmp(STR_CAMERA, sdl->block_1) != 0) &&
				(ft_strcmp(STR_LIGHT, sdl->block_1) != 0))
		{
			if (!check_blok_4(sdl))
				return (FALSE);
			if (!check_blok_5(sdl))
				return (FALSE);
			if ((ft_strcmp(STR_SPHERE, sdl->block_1) != 0) &&
					(ft_strcmp(STR_PLANE, sdl->block_1) != 0))
				if (!check_blok_6(sdl))
					return (FALSE);
		}
	}
	return (TRUE);
}
