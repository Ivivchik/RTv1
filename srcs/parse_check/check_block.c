/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 21:07:35 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/24 22:12:17 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			check_blok_2(t_sdl *sdl)
{
	if (!sdl->block_2 || !try_find_params_2(sdl->block_1, sdl->block_2))
		return (FALSE);
	return (TRUE);
}

int			check_blok_3(t_sdl *sdl)
{
	if (!sdl->block_3 || !try_find_params_3(sdl->block_1, sdl->block_3))
		return (FALSE);
	return (TRUE);
}

int			check_blok_4(t_sdl *sdl)
{
	if (!sdl->block_4 || !try_find_params_4(sdl->block_1, sdl->block_4))
		return (FALSE);
	return (TRUE);
}

int			check_blok_5(t_sdl *sdl)
{
	if (!sdl->block_5 || !try_find_params_5(sdl->block_1, sdl->block_5))
		return (FALSE);
	return (TRUE);
}

int			check_blok_6(t_sdl *sdl)
{
	if (!sdl->block_6 || !try_find_params_6(sdl->block_1, sdl->block_6))
		return (FALSE);
	return (TRUE);
}
