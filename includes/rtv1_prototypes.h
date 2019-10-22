/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_prototypes.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 16:20:57 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/22 17:26:25 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_PROTOTYPES_H
# define RTV1_PROTOTYPES_H

/*
** Main functions
*/
void		ft_close(t_sdl **sdl);
void		ft_init(t_sdl **sdl);
void		sdl_loop(t_sdl *sdl);
void		how_to_use(void);

/*
** Read functions
*/
void		read_init(t_sdl **sdl, char *argv);
int			put_error_sdl(char *str, const char *err);

/*
** Parse functions
*/
int			parse_check(t_sdl *sdl, char *av);

/*
** Render functions
*/
void		sdl_render(t_sdl *sdl);
t_vec3		cast_ray(t_ray ray, t_sdl *sdl);
t_ray		new_ray(t_vec3 orig, t_vec3 dir);

/*
** SDL functions
*/
SDL_Surface	*create_surface(int width, int height);

/*
** Object functions
*/
t_sphere	*create_null_list_spheres(int nbr);
t_cone		*create_null_list_cone(int nbr);
t_plane		*create_null_list_plane(int nbr);
t_cylin		*create_null_list_cylinder(int nbr);
t_light		*create_null_list_lights(int nbr);
t_light		light_new(t_vec3 pos, double intens);
t_sphere	sphere_new(t_vec3 center, double radius,
		double blesk, t_vec3 color);
t_cone		cone_new(t_cone		pars_cone);
t_plane		plane_new(t_vec3 norm, t_vec3 line,
		double blesk, t_vec3 color);
t_cylin		cylin_new(t_cylin		pars_cylin);
void		fill_objs_sphere(t_obj ***all_obj,
		t_sphere *sphere, int *i, int max);
void		fill_objs_cone(t_obj ***all_obj, t_cone *cone, int *i, int max);
void		fill_objs_plane(t_obj ***all_obj, t_plane *plane, int *i, int max);
void		fill_objs_cylin(t_obj ***all_obj,
		t_cylin *cylindr, int *i, int max);
void		init_obj(t_obj ***all_obj, int *num, t_sdl *sdl);

/*
** Camera functions
*/
t_ray		get_camera_ray(t_sdl *sdl, SDL_Surface *surf, int x, int y);

/*
** Color pack functions
*/
uint32_t	pack_color(const uint8_t r, const uint8_t g, const uint8_t b);
void		unpack_color(uint32_t color, uint8_t *r, uint8_t *g, uint8_t *b);

/*
** Set_pixel on surface SDL
*/
void		put_pixel(SDL_Surface *surf,
		const int x, const int y, const int color);

/*
** Some scene function
*/
void		scene1(t_sdl **sdl);
void		scene2(t_sdl **sdl);
void		scene3(t_sdl **sdl);
void		scene4(t_sdl **sdl);
void		scene4_1(t_sdl **sdl);
void		scene4_2(t_sdl **sdl);
void		scene5(t_sdl **sdl);
void		scene5_1(t_sdl **sdl);
void		scene5_2(t_sdl **sdl);
int			exec_1(t_all_obj *objs, t_sdl *sdl);
void		load_1(int *i, int **nbr, t_sdl	*sdl);

/*
** scene1
*/
t_sphere	*exec_sphere_1(t_sdl *sdl);
t_cone		*exec_cone_1(t_sdl *sdl);
t_cylin		*exec_cylinder_1(t_sdl *sdl);
t_plane		*exec_plane_1(t_sdl *sdl);

/*
** Drawer functions for scene
*/
void		draw_scene_main(SDL_Surface *surf, t_sdl **sdl);

/*
** Comput light functions
*/
double		computer_lighting(t_vec3 p, t_vec3 n, t_sdl *rt, t_vec3 v);
uint8_t		calc_shadow(t_calc_light me, t_sdl *sdl);

/*
** Cast ray for objects
*/
double		*cast_ray_for_obj(t_sdl *sdl, t_ray ray, int i);
double		*intersec_sphere(t_ray ray, t_sphere s, t_sdl *sdl, double **bb);
double		*intersec_conus(t_ray ray, t_cone s, t_sdl *sdl, double **bb);
double		*intersec_plane(t_ray ray, t_plane s, t_sdl *sdl, double **bb);
double		*intersec_cylinder(t_ray ray, t_cylin s, t_sdl *sdl, double **bb);

/*
** Find normal for objects
*/
t_vec3		normal_cone(t_vec3 p, int i, t_sdl *sdl);
t_vec3		normal_cylinder(t_vec3 p, int i, t_sdl *sdl, double close_t);
t_vec3		normal_plane(t_vec3 p, int i, t_sdl *sdl);
t_vec3		normal_sphere(t_vec3 p, int i, t_sdl *sdl);

/*
** buff color, blesk and centr in sdl
*/
void		mem_sdl_buf_sph(t_sdl **sdl, t_sphere sph);
void		mem_sdl_buf_con(t_sdl **sdl, t_cone con);
void		mem_sdl_buf_cyl(t_sdl **sdl, t_cylin cyl);
void		mem_sdl_buf_pla(t_sdl **sdl, t_plane pla);

/*
** Memory func for search type obj
*/
t_sphere	get_sph(void *sdl_sph);
t_cone		get_con(void *sdl_o);
t_plane		get_pla(void *sdl_p);
t_cylin		get_cyl(void *sdl_c);

/*
** Fill obj
*/
void		fill_camera(char **split, t_vec3 *from, t_vec3 *lookat);
void		fill_light(char **split, t_light *new_light, int *i);
void		fill_sphere(char **split, t_sphere *new_sphere, int *i);
void		fill_plane(char **split, t_plane *new_plane, int *i);
void		fill_cone(char **split, t_cone *new_cone, int *i);
void		fill_cylin(char **split, t_cylin *new_cylinder, int *i);

void		get_list_objs(t_sdl *sdl2, char *path);

#endif
