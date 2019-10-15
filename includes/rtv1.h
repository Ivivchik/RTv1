/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 16:30:29 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/15 23:04:37 by hkuhic           ###   ########.fr       */
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
# define SCENE5 "scene5"

# define SCENE1_IMG 1
# define SCENE2_IMG 2
# define SCENE3_IMG 3
# define SCENE4_IMG 4
# define SCENE5_IMG 5

# define MAX_DIST 1.7976931348623158e+308
# define MIN_DIST 1 //0.00000001
# define FALSE 0
# define TRUE 1
# define PI 3.14159265359
# define FOV PI/2

/*
**	Fill scenes1
*/
# define NUMB_OBJ_IN_SCENE1     4
# define NUMB_SPHERE_IN_SCENE1  4
# define NUMB_PLANE_IN_SCENE1   0
# define NUMB_CONE_IN_SCENE1    0
# define NUMB_CYLINDR_IN_SCENE1 0
/*
**	Fill scenes2
*/
# define NUMB_OBJ_IN_SCENE2     3
# define NUMB_SPHERE_IN_SCENE2  0
# define NUMB_PLANE_IN_SCENE2   1
# define NUMB_CONE_IN_SCENE2    1
# define NUMB_CYLINDR_IN_SCENE2 1
/*
**	Fill scenes3
*/
# define NUMB_OBJ_IN_SCENE3     7
# define NUMB_SPHERE_IN_SCENE3  2
# define NUMB_PLANE_IN_SCENE3   3
# define NUMB_CONE_IN_SCENE3    1
# define NUMB_CYLINDR_IN_SCENE3 1
/*
**	Fill scenes4
*/
# define NUMB_OBJ_IN_SCENE4     0
# define NUMB_SPHERE_IN_SCENE4  0
# define NUMB_PLANE_IN_SCENE4   0
# define NUMB_CONE_IN_SCENE4    0
# define NUMB_CYLINDR_IN_SCENE4 0
/*
**	Fill scenes5
*/
# define NUMB_OBJ_IN_SCENE5     0
# define NUMB_SPHERE_IN_SCENE5  0
# define NUMB_PLANE_IN_SCENE5   0
# define NUMB_CONE_IN_SCENE5    0
# define NUMB_CYLINDR_IN_SCENE5 0

/*
**	materials
*/
# define MAT_IVORY "ivory"
# define MAT_RED_RUBBER "red_rubber"
# define MAT_MIRROR "mirror"
# define MAT_METAL "metal"
# define MAT_LAMBERT "lambert"

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
