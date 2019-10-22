/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 01:17:52 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/21 22:50:06 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		sdl_render(t_sdl *sdl)
{
	scene1(&sdl);
	SDL_BlitSurface(sdl->image, NULL, sdl->screen, NULL);
	SDL_UpdateWindowSurface(sdl->win);
	return ;
}
