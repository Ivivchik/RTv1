/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 00:53:20 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/12 01:12:21 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int   put_error_sdl(char *str, const char *err)
{
  if (str && err)
  {
    if (ft_strcmp(str,SDL_ERROR) == 0)
      ft_putstr(SDL_ERROR);
    else if (ft_strcmp(str,WIN_ERROR) == 0)
      ft_putstr(WIN_ERROR);
    else if (ft_strcmp(str,SUR_ERROR) == 0)
      ft_putstr(SUR_ERROR);
    ft_putstr(err);
    ft_putstr("\n");
  }
  return (0);
}
