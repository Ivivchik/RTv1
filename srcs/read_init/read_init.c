/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 00:45:29 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/25 04:12:54 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static uint8_t	init_sdl(t_sdl **sdl)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return (put_error_sdl(SDL_ERROR, SDL_GetError()));
	else
	{
		if (!((*sdl)->win = SDL_CreateWindow(WIN_TITLE,
						SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
						WIN_WIDTH, WIN_HEIGHT,
						SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE)))
			return (put_error_sdl(WIN_ERROR, SDL_GetError()));
		else
		{
			if (!((*sdl)->screen = SDL_GetWindowSurface((*sdl)->win)))
				return (put_error_sdl(SUR_ERROR, SDL_GetError()));
		}
	}
	return (TRUE);
}

void			ft_init(t_sdl **sdl)
{
	if (!((*sdl) = ft_memalloc(sizeof(t_sdl))))
		ft_print_error_exit(&ft_putendl, "Error");
	(*sdl)->win = NULL;
	(*sdl)->screen = NULL;
	(*sdl)->image = NULL;
	(*sdl)->run_main = 1;
	(*sdl)->obj = NULL;
	(*sdl)->rot_ang = vec_new(0, 0, 0);
	if (!(init_sdl(sdl)))
		ft_print_error_exit(&ft_putendl, "Error_sdl");
	return ;
}

void			ft_close(t_sdl **sdl)
{
	SDL_DestroyWindow((*sdl)->win);
	(*sdl)->win = NULL;
	IMG_Quit();
	SDL_Quit();
	return ;
}

void			read_init(t_sdl **sdl, char *av)
{
	ft_init(sdl);
	if (!(parse_check(*sdl, av)))
		exit(1);
	get_list_objs(*sdl, av);
	return ;
}
