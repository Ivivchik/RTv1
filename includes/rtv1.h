/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 16:30:29 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/22 18:51:40 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <SDL.h>
# include <SDL_image.h>
# include <SDL_mixer.h>
# include <SDL_ttf.h>
# include <math.h>
# include "libft.h"
# include "rtv1_structs.h"
# include "rtv1_prototypes.h"

# define WIN_TITLE "RTv1 - SDL"

# define WIN_WIDTH 1200
# define WIN_HEIGHT 1200

# define SCENE1 "scene1"

# define MAX_DIST 1.7976931348623158e+308
# define MIN_DIST 0.00000001
# define FALSE 0
# define TRUE 1
# define PI 3.14159265359
# define X_LINZE 2

/*
**	Objects
*/
# define STR_CAMERA   "camera"
# define STR_LIGHT    "light"
# define STR_SPHERE   "sphere"
# define STR_PLANE    "plane"
# define STR_CONE     "cone"
# define STR_CYLINDR  "cylindre"

/*
**	Some errors
*/
# define SDL_ERROR "SDL could not initialize! SDL Error: "
# define WIN_ERROR "Window could not be created! SDL Error: "
# define SUR_ERROR "Surface_window could not be created! SDL Error: "

#endif
