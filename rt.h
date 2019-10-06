/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 20:10:58 by hkuhic            #+#    #+#             */
/*   Updated: 2019/10/06 21:46:52 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H
# define WIDTH 1920
# define HEIGHT 1080
# define TMAX 2147483647
# define TMIN 1
# include <mlx.h>
# include <math.h>
# include <stdlib.h>

typedef struct	s_coord
{
	double x;
	double y;
	double z;
}				t_coord;

typedef struct	s_sphere
{
	t_coord	center;
	int		radius;
	t_coord	color;
}				t_sphere;

typedef struct	s_rt
{
	int			vh;
	int			vw;
	int			vz;
	void		*mlx;
	void		*win;
	t_coord		camera;
	t_coord		vector;
	t_sphere	sphere;
	t_coord		viewport;
	double		k1;
	double		k2;
	double		k3;
}				t_rt;

#endif
