/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 16:20:54 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/25 04:15:22 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_STRUCTS_H
# define RTV1_STRUCTS_H

# include "rtv1_vec3.h"

/*
**	Ray
*/
typedef struct		s_ray
{
	t_vec3	origin;
	t_vec3	direct;
}					t_ray;

/*
**	Objects
*/
typedef struct		s_obj
{
	void	*type;
	char	*c_type;
}					t_obj;

/*
**	Sphere
*/
typedef struct		s_sphere
{
	double	radius;
	t_vec3	center;
	t_vec3	color;
	double	blesk;
}					t_sphere;

/*
**	Plane
*/
typedef struct		s_plane
{
	t_vec3	norm;
	t_vec3	line;
	t_vec3	color;
	double	blesk;
}					t_plane;

/*
**	Cone
*/
typedef struct		s_cone
{
	t_vec3			center;
	t_vec3			vector;
	t_vec3			color;
	double			ang;
	double			blesk;
}					t_cone;

/*
**	Cylin
*/
typedef struct		s_cylin
{
	t_vec3	center;
	t_vec3	vector;
	t_vec3	color;
	double	blesk;
	double	radius;
}					t_cylin;

typedef struct		s_all_obj
{
	t_sphere	*new_sphere;
	t_cone		*new_cone;
	t_plane		*new_plane;
	t_cylin		*new_cylinder;
}					t_all_obj;

/*
**	Light
*/
typedef struct		s_light
{
	double	intens;
	t_vec3	pos;
}					t_light;

typedef struct		s__calc_light
{
	t_light	l;
	t_vec3	n;
	t_vec3	p;
	t_vec3	v;
}					t_calc_light;

/*
**	Buffer_color
*/
typedef struct		s_buf_color
{
	double ble;
	t_vec3 col;
	t_vec3 cen;
}					t_buf_color;

/*
**	After parse nbrs
*/
typedef struct		s_nbr_all
{
	int				num_obj;
	int				num_sph;
	int				num_pla;
	int				num_con;
	int				num_cyl;
	int				num_lig;
	int				num_cam;
	int				num_amb;
}					t_nbr_all;

/*
**	Main struct
*/
typedef struct		s_sdl
{
	SDL_Window		*win;
	SDL_Surface		*screen;
	SDL_Surface		*image;
	SDL_Event		event;
	uint8_t			run_main;
	uint8_t			scene_num;
	t_obj			**obj;
	t_light			*light;
	double			k1;
	double			k2;
	double			k3;
	double			dis;
	double			n_dot_l;
	double			r_dot_v;
	double			intens;
	t_vec3			f_center;
	double			f_blesk;
	t_vec3			f_color;
	t_vec3			norm_cone;
	t_ray			norm_cylin;
	double			k;
	t_vec3			lookat;
	t_vec3			lookfr;
	t_vec3			rot_ang;
	t_nbr_all		nbrs;
	char			*block_1;
	char			*block_2;
	char			*block_3;
	char			*block_4;
	char			*block_5;
	char			*block_6;
	double			ambient;
}					t_sdl;

#endif
