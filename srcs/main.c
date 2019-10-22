/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 18:32:56 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/22 18:53:30 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			print_inform(t_sdl *sdl)
{
	printf("After parsing =========================\n");
	printf("=======================================\n");
	printf("vec_from=%f,%f,%f vec_looat=%f,%f,%f\n", sdl->lookfr.x,
	sdl->lookfr.y, sdl->lookfr.z, sdl->lookat.x, sdl->lookat.y, sdl->lookat.z);
	printf("SDL_NBRS cam=%d sphere=%d plane=%d\n", sdl->nbrs.num_cam,
	sdl->nbrs.num_sph, sdl->nbrs.num_pla);
	printf("SDL_NBRS con=%d cylindr=%d light=%d\n", sdl->nbrs.num_con,
	sdl->nbrs.num_cyl, sdl->nbrs.num_lig);
	printf("SDL_ALL=%d\n", sdl->nbrs.num_obj);
	printf("\n==========LIGHT========\n");
	printf("#0 x=%f y=%f z=%f", sdl->light[0].pos.x,
	sdl->light[0].pos.y, sdl->light[0].pos.z);
}

void			how_to_use(void)
{
	ft_print_error_exit(&ft_putendl, "Usage: ./RTv1 scene1");
}

int				main(int argc, char **argv)
{
	t_sdl		*sdl;

	if (argc != 2)
		how_to_use();
	read_init(&sdl, argv[1]);
	print_inform(sdl);
	sdl_render(sdl);
	sdl_loop(sdl);
	ft_close(&sdl);
	return (0);
}
