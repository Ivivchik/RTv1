/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_buf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 01:49:32 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/19 07:41:59 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	mem_sdl_buf_sph(t_sdl **sdl, t_sphere sph)
{
	(*sdl)->f_center = sph.center;
	(*sdl)->f_blesk = sph.blesk;
	(*sdl)->f_color = sph.color;
	return ;
}

void	mem_sdl_buf_con(t_sdl **sdl, t_cone con)
{
	(*sdl)->f_center = con.center;
	(*sdl)->f_blesk = con.blesk;
	(*sdl)->f_color = con.color;
	(*sdl)->k = con.ang;
	(*sdl)->norm_cone = con.vector;
	return ;
}

void	mem_sdl_buf_cyl(t_sdl **sdl, t_cylin cyl)
{
	(*sdl)->f_center = cyl.center;
	(*sdl)->f_blesk = cyl.blesk;
	(*sdl)->f_color = cyl.color;
	return ;
}

void	mem_sdl_buf_pla(t_sdl **sdl, t_plane pla)
{
	(*sdl)->f_center = pla.norm;
	(*sdl)->f_blesk = pla.blesk;
	(*sdl)->f_color = pla.color;
	return ;
}
