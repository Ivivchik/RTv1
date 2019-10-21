/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 01:17:52 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/20 12:06:12 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	choose_scene(t_sdl **sdl)
{
	if ((*sdl)->scene_num == SCENE1_IMG)
		scene1(sdl);
	else if ((*sdl)->scene_num == SCENE2_IMG)
		scene2(sdl);
	else if ((*sdl)->scene_num == SCENE3_IMG)
		scene3(sdl);
	else if ((*sdl)->scene_num == SCENE4_IMG)
		scene4(sdl);
	else if ((*sdl)->scene_num == SCENE4_1_IMG)
		scene4_1(sdl);
	else if ((*sdl)->scene_num == SCENE4_2_IMG)
		scene4_2(sdl);
	else if ((*sdl)->scene_num == SCENE5_IMG)
		scene5(sdl);
	else if ((*sdl)->scene_num == SCENE5_1_IMG)
		scene5_1(sdl);
	else if ((*sdl)->scene_num == SCENE5_2_IMG)
		scene5_2(sdl);
	else
		ft_print_error_exit(&ft_putendl, "Error not_scene");
	return ;
}

void		sdl_render(t_sdl *sdl)
{
	choose_scene(&sdl);
	SDL_BlitSurface(sdl->image, NULL, sdl->screen, NULL);
	SDL_UpdateWindowSurface(sdl->win);
	return ;
}
