/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 18:32:56 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/12 22:46:11 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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
	//sdl_render(sdl);// loaded after press <- arrorw onkeyboard(check sdl_loop);
	sdl_loop(sdl);
	ft_close(&sdl);
	return (0);
}
