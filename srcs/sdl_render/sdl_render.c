/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 01:17:52 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/12 05:03:57 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		choose_scene(t_sdl **sdl)
{
	if ((*sdl)->scene_num == SCENE1_IMG)
		scene1(sdl);
	else if ((*sdl)->scene_num == SCENE2_IMG)
		scene2(sdl);
	else if ((*sdl)->scene_num == SCENE3_IMG)
		scene3(sdl);
	else if ((*sdl)->scene_num == SCENE4_IMG)
		scene4(sdl);
	else if ((*sdl)->scene_num == SCENE5_IMG)
		scene5(sdl);
	else
		ft_print_error_exit(&ft_putendl, "Error not_scene");
	return ;
}

void		sdl_render(t_sdl *sdl)
{
	choose_scene(&sdl);
	SDL_BlitSurface( sdl->image, NULL, sdl->screen, NULL );
	SDL_UpdateWindowSurface(sdl->win);
	return ;
}
