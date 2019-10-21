/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 01:33:45 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/21 19:56:53 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

uint32_t	pack_color(const uint8_t r, const uint8_t g, const uint8_t b)
{
	uint8_t	a;

	a = 255;
	return (r | g << 8 | b << 16 | a << 24);
}

void		unpack_color(uint32_t color, uint8_t *r, uint8_t *g, uint8_t *b)
{
	*r = (color >> 0) & 255;
	*g = (color >> 8) & 255;
	*b = (color >> 16) & 255;
	return ;
}

void		put_pixel(SDL_Surface *surf, const int x,
		const int y, const int color)
{
	uint32_t		*pixels;

	if (x >= 0 && y >= 0 && x < surf->w && y < surf->h)
	{
		pixels = (uint32_t *)surf->pixels;
		pixels[y * surf->w + x] = color;
	}
}

uint32_t	read_pixel(SDL_Surface *surf, const int x, const int y)
{
	uint32_t	pixel;

	if (x >= 0 && y >= 0 && x < surf->w && y < surf->h)
		pixel = (Uint32)(surf->pixels + y * surf->w + x);
	else
		pixel = 0;
	return (pixel);
}
