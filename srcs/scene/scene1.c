/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 00:05:03 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/25 05:51:11 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			scene1(t_sdl **sdl)
{
	SDL_Surface	*frame;

	frame = create_surface(WIN_WIDTH, WIN_HEIGHT);
	draw_scene_main(frame, sdl);
	(*sdl)->image = frame;
	return ;
}
