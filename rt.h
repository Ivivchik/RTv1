/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 20:10:58 by hkuhic            #+#    #+#             */
/*   Updated: 2019/10/10 20:49:58 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H
# define WIDTH 900
# define HEIGHT 900
# define TMAX 2147483647
# define TMIN 1
# include <mlx.h>
# include <math.h>
# include <stdlib.h>

typedef struct	s_coord
{
	double		x;
	double		y;
	double		z;
}				t_coord;

typedef struct	s_sphere
{
	t_coord		center;
	t_coord		color;
	double		radius;
	int			blesk;
}				t_sphere;

typedef struct	s_light
{
	double		inten;
	t_coord		pos;
}				t_light;

typedef struct	s_cylinder
{
	t_coord a;
	t_coord color;
	t_coord	b;
	double	radius;
	int		blesk;
}				t_cylinder;

typedef	struct	s_plane
{
	t_coord m0;
	t_coord m1;
	t_coord m2;
	t_coord color;
}				t_plane;

typedef struct	s_rt
{
	int			vh;
	int			vw;
	int			vz;
	void		*mlx;
	void		*win;
	t_coord		camera;
	t_coord		light;
	t_coord		vector;
	t_sphere	sphere;
	t_cylinder	cylinder;
	t_plane		plane;
	t_coord		viewport;
	double		k1;
	double		k2;
	double		k3;
	double		dis;
	double		n_dot_l;
	double		r_dot_v;
	double		intens;
}				t_rt;

int				key(int keycode, t_rt *rt);

#endif
