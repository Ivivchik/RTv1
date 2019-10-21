/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 00:30:14 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/21 22:45:11 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void foo()
{
	printf("REsized!!\n");
}

void		sdl_loop(t_sdl *sdl)
{
	while (sdl->run_main)
	{
		while (SDL_PollEvent(&(sdl->event)) != 0)
		{
			if ((SDL_QUIT == sdl->event.type) ||
					(SDL_KEYDOWN == sdl->event.type &&
						SDL_SCANCODE_ESCAPE == sdl->event.key.keysym.scancode))
				sdl->run_main = 0;
			else if (sdl->event.type == SDL_WINDOWEVENT_RESIZED)
			{
				foo();				
			}
		}
	}
	return ;
}
