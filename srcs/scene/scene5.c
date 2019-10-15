/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 00:05:03 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/12 01:55:58 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void    scene5(t_sdl **sdl)
{
  SDL_Surface		*frame;

  frame = create_surface(200,200);

  int i,j;
  i = -1;
  while (++i < frame->h)
  {
    j = -1;
    while (++j < frame->w)
    {
      if (j < frame->w/2)
      {
        if (i < frame->h/2)
          put_pixel(frame, j, i, pack_color(0,0,255));
        else
          put_pixel(frame, j, i, pack_color(0,255,0));
      }
      else
        if (i < frame->h/2)
          put_pixel(frame, j, i, pack_color(255,0,0));
        else
          put_pixel(frame, j, i, pack_color(255,255,255));
    }
  }
  //SDL_Surface *test = SDL_LoadBMP( "textures/Canada-Flag.bmp" );
  //SDL_BlitSurface( test, NULL, (*sdl)->screen, NULL );
  (*sdl)->image = frame;
  ft_putstr("Loading: scene5\n");
  return;
}
