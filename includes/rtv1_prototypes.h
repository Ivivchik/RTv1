/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_prototypes.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 16:20:57 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/25 04:14:52 by gwaymar-         ###   ########.fr       */
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
void		fill_all_parse(t_light **new_light,
			t_all_obj *objs, t_sdl *sdl, char *path);

/*
** Valid_parse
*/
int			check_all_block(t_sdl *sdl);
int			valid_param(t_sdl *sdl, char *path);
int			check_blok_1(t_sdl *sdl);
int			try_find_objs(char *obj_block);
void		init_bloks(t_sdl *sdl, char **split);
int			check_blok_2(t_sdl *sdl);
int			check_blok_3(t_sdl *sdl);
int			check_blok_4(t_sdl *sdl);
int			check_blok_5(t_sdl *sdl);
int			check_blok_6(t_sdl *sdl);
int			try_find_params_2(char *block1, char *block2);
int			try_find_params_3(char *block1, char *block3);
int			try_find_params_4(char *block1, char *block4);
int			try_find_params_5(char *block1, char *block5);
int			try_find_params_6(char *block1, char *block6);
double		valid_intens(double n);
double		valid_radius(double n);
double		valid_blesk(double n);

/*
** Valid_parse_helper
*/
int			str_count_c(char *str, char c);
int			check_letter_alnum(char *str);
int			check_letter_num(char *str);
int			check_letter_hex(char *str);
int			is_hex(int c);
int			str_count_c(char *str, char c);
int			check_str_to_hex(char *block);
int			check_str_to_double(char *block);
int			check_str_to_vec3(char *block);
t_nbr_all	nbr(void);
int			wrong_param_false(void);

/*
** Free_parse_helper
*/
void		free_tmp_free_split(char **tmp, char ***str);
int			free_split_vec3_true(char ***str);
int			free_split_double_true(char ***str, char **bzero);
int			free_split_double_false(char ***str, char **bzero);
int			false_free_close_split(char **tmp, int *fd, char ***str);
int			false_free_close(char **tmp, int *fd);

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

/*
** Malloc_types_for_objects
*/
t_sphere	*exec_sphere_1(t_sdl *sdl);
t_cone		*exec_cone_1(t_sdl *sdl);
t_cylin		*exec_cylinder_1(t_sdl *sdl);
t_plane		*exec_plane_1(t_sdl *sdl);
t_light		*exec_light_1(t_sdl *sdl);

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
void		fill_ambient(char **split, double *amb);

void		get_list_objs(t_sdl *sdl2, char *path);

#endif
