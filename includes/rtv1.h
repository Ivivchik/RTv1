/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 16:30:29 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/21 20:36:27 by hkuhic           ###   ########.fr       */
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
# define SCENE2 "scene2"
# define SCENE3 "scene3"
# define SCENE4 "scene4"
# define SCENE4_1 "scene4_1"
# define SCENE4_2 "scene4_2"
# define SCENE5 "scene5"
# define SCENE5_1 "scene5_1"
# define SCENE5_2 "scene5_2"

# define SCENE1_IMG 1
# define SCENE2_IMG 2
# define SCENE3_IMG 3
# define SCENE4_IMG 4
# define SCENE4_1_IMG 6
# define SCENE4_2_IMG 7
# define SCENE5_IMG 5
# define SCENE5_1_IMG 8
# define SCENE5_2_IMG 9

# define MAX_DIST 1.7976931348623158e+308
# define MIN_DIST 0.00000001
# define FALSE 0
# define TRUE 1
# define PI 3.14159265359
# define X_LINZE 2

/*
**	Fill scenes1
*/
# define NUMB_OBJ_IN_SCENE1     1
# define NUMB_SPHERE_IN_SCENE1  1
# define NUMB_PLANE_IN_SCENE1   0
# define NUMB_CONE_IN_SCENE1    0
# define NUMB_CYLINDR_IN_SCENE1 0

# define NUMB_LIGHTS_IN_SCENE1  2
/*
**	Fill scenes2
*/
# define NUMB_OBJ_IN_SCENE2     1
# define NUMB_SPHERE_IN_SCENE2  0
# define NUMB_PLANE_IN_SCENE2   0
# define NUMB_CONE_IN_SCENE2    0
# define NUMB_CYLINDR_IN_SCENE2 1

# define NUMB_LIGHTS_IN_SCENE2  2
/*
**	Fill scenes3
*/
# define NUMB_OBJ_IN_SCENE3     2
# define NUMB_SPHERE_IN_SCENE3  0
# define NUMB_PLANE_IN_SCENE3   1
# define NUMB_CONE_IN_SCENE3    1
# define NUMB_CYLINDR_IN_SCENE3 0

# define NUMB_LIGHTS_IN_SCENE3  2
/*
**	Fill scenes4
*/
# define NUMB_OBJ_IN_SCENE4     7
# define NUMB_SPHERE_IN_SCENE4  2
# define NUMB_PLANE_IN_SCENE4   3
# define NUMB_CONE_IN_SCENE4    1
# define NUMB_CYLINDR_IN_SCENE4 1

# define NUMB_LIGHTS_IN_SCENE4  2
/*
**	Fill scenes5
*/
# define NUMB_OBJ_IN_SCENE5     16
# define NUMB_SPHERE_IN_SCENE5  9
# define NUMB_PLANE_IN_SCENE5   3
# define NUMB_CONE_IN_SCENE5    0
# define NUMB_CYLINDR_IN_SCENE5 4

# define NUMB_LIGHTS_IN_SCENE5  1

/*
**	Objects
*/
# define STR_SPHERE   "sphere"
# define STR_PLANE    "plane"
# define STR_CONE     "cone"
# define STR_CYLINDR  "cylindr"

/*
**	Some errors
*/
# define SDL_ERROR "SDL could not initialize! SDL Error: "
# define WIN_ERROR "Window could not be created! SDL Error: "
# define SUR_ERROR "Surface_window could not be created! SDL Error: "

#endif
