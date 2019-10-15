/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_prototypes.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 16:20:57 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/15 21:54:54 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_PROTOTYPES_H
# define RTV1_PROTOTYPES_H

/*
** Main functions
*/
void          ft_close(t_sdl **sdl);
void          ft_init(t_sdl **sdl, uint8_t sc);
void		      sdl_loop(t_sdl *sdl);
void          how_to_use(void);

/*
** Read functions
*/
void          read_init(t_sdl **sdl, char *argv);
int           put_error_sdl(char *str, const char *err);

/*
** Render functions
*/
void          sdl_render(t_sdl *sdl);
t_vec3        cast_ray(t_vec3 b, t_sdl *sdl);

/*
** SDL functions
*/
SDL_Surface		*create_surface(int width, int height);

/*
** Object functions
*/
t_sphere		*create_null_list_spheres(int nbr);
t_cone			*create_null_list_cone(int nbr);
t_plane    *create_null_list_plane(int nbr);
t_cylin    *create_null_list_cylinder(int nbr);
//t_sphere    sphere_new(t_vec3 center, double radius, t_mater mater); // using blesk <<<<<<<<<< !!!!
t_sphere		sphere_new(t_vec3 center, double radius, double blesk, t_vec3 color);
t_cone			cone_new(t_vec3 center, t_vec3 vector, double blesk, t_vec3 color, double ang);
t_plane    plane_new(t_vec3 norm, t_vec3 line, double blesk, t_vec3 color);
t_cylin    cylin_new(t_vec3 center, t_vec3 vector, double radius, double blesk, t_vec3 color);
void          fill_objs_sphere(t_obj   ***all_obj, t_sphere *sphere, int *i, int max);
void          fill_objs_cone(t_obj ***all_obj, t_cone *cone, int *i, int max);
void          fill_objs_plane(t_obj ***all_obj, t_plane *plane, int *i, int max);
void          fill_objs_cylin(t_obj ***all_obj, t_cylin *cylindr, int *i, int max);      // need ADD t_cylindr

/*
** Material functions
*/
t_mater       mater_new(void);
void          mater_fill(t_mater *mat, char *mat_type);
void          fill_mat_ivory(t_mater *mat);
void          fill_mat_lambert(t_mater *mat);
void          fill_mat_metal(t_mater *mat);
void          fill_mat_mirror(t_mater *mat);
void          fill_mat_red_rub(t_mater *mat);


/*
** Camera functions
*/
t_vec3        tranform_to_viewport(int x, int y, int w, int h);

/*
** Color pack functions
*/
uint32_t      pack_color(const uint8_t r, const uint8_t g, const uint8_t b);
void          unpack_color( uint32_t color, uint8_t *r, uint8_t *g, uint8_t *b);

/*
** Set_pixel on surface SDL
*/
void          put_pixel(SDL_Surface *surf, const int x, const int y, const int color);

/*
** Some scene function
*/
void          scene1(t_sdl **sdl);
void          scene2(t_sdl **sdl);
void          scene3(t_sdl **sdl);
void          scene4(t_sdl **sdl);
void          scene5(t_sdl **sdl);

/*
** Drawer functions for scenes
*/
void          draw_scene1(SDL_Surface *surf, t_sdl  **sdl);

/*
** Cast ray for objects
*/
double			*intersec_sphere(t_vec3 a, t_vec3 b, t_sphere s, t_sdl *sdl);
double			*intersec_conus(t_vec3 a, t_vec3 b, t_cone s, t_sdl *sdl);
double		intersec_plane(t_vec3 a, t_vec3 b, t_plane s, t_sdl *sdl);
double		*intersec_cylinder(t_vec3 a, t_vec3 b, t_cylin s, t_sdl *sdl);

/*
** Memory func for search type obj
*/
t_sphere			get_sph(void *sdl_sph);
t_cone				get_con(void *sdl_o);
t_plane				get_pla(void *sdl_p);
t_cylin				get_cyl(void *sdl_c);

#endif
