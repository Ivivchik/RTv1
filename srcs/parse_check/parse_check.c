/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 22:28:32 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/22 17:58:19 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			str_count_c(char *str, char c)
{
	int	count;
	int	i;
	int	len;

	if (str)
	{
		count = 0;
		len = ft_strlen(str);
		i = -1;
		while (++i < len)
		{
			if (str[i] == c)
				count++;
		}
	}
	return (count);
}

int			check_letter_alph(char *str)
{
	int	i;
	int	len;

	len = ft_strlen(str);
	i = -1;
	while (++i < len)
	{
		if (!(ft_isalpha(str[i])))
			return (FALSE);
	}
	return (TRUE);
}

int			check_letter_num(char *str)
{
	int		i;
	int		len;

	len = ft_strlen(str);
	i = -1;
	while (++i < len)
	{
		if (!(ft_isdigit(str[i])))
			return (FALSE);
	}
	return (TRUE);
}

int			check_letter_alnum(char *str)
{
	int		i;
	int		len;

	len = ft_strlen(str);
	i = -1;
	while (++i < len)
	{
		if (!(ft_isalnum(str[i])))
			return (FALSE);
	}
	return (TRUE);
}

// int   check_str_to_hex(char *block)
// {
//   if (ft_strlen(block) == 6)
//   {
//     if (check_letter_alnum(block))
//     {
//       return (TRUE);
//     }
//   }
//   return (FALSE);
// }

int			check_str_to_double(char *str)
{
	char		**str_double;
	char		*double_b_zero;

	str_double = ft_strsplit(str, '.');
	if (str_double[0])
		double_b_zero = ft_strsub(str_double[0], 1, ft_strlen(str_double[0]) - 1);
	if (str_count_c(str, '.') == 0)
	{
		if (str_double[0] &&
				(check_letter_num(str_double[0]) || (check_letter_num(double_b_zero) && str_double[0][0] == '-')))
			return (TRUE);
	}
	if (str_count_c(str, '.') == 1)
	{
		if (str_double[0] && str_double[1] &&
				check_letter_num(str_double[1]) &&
				(check_letter_num(str_double[0]) || (check_letter_num(double_b_zero) && str_double[0][0] == '-')))
			return (TRUE);
	}
	printf("double_min=//False");
	return (FALSE);
}

int			check_str_to_vec3(char *block)
{
	char		**str_vec;

	if (str_count_c(block, ',') == 2)
	{
		str_vec = ft_strsplit(block, ',');
		if ((str_vec[0] && str_vec[1] && str_vec[2]) &&
				(check_str_to_double(str_vec[0])) &&
				(check_str_to_double(str_vec[1])) &&
				(check_str_to_double(str_vec[2])))
		{
			printf("gogosgo\n\n");
			return (TRUE);
		}
	}
	return (FALSE);
}

int			try_find_objs(char *obj_block)
{
	if ((ft_strcmp(STR_CAMERA, obj_block) == 0) ||
		(ft_strcmp(STR_LIGHT, obj_block) == 0) ||
		(ft_strcmp(STR_SPHERE, obj_block) == 0) ||
		(ft_strcmp(STR_PLANE, obj_block) == 0) ||
		(ft_strcmp(STR_CONE, obj_block) == 0) ||
		(ft_strcmp(STR_CYLINDR, obj_block) == 0))
		return (TRUE);
	return (FALSE);
}

int			try_find_params_2(char *block1, char *block2)
{
	if (!check_str_to_vec3(block2))
		return (FALSE);
	return (TRUE);
}

int			try_find_params_3(char *block1, char *block3)
{
	if ((ft_strcmp(STR_LIGHT, block1) == 0) || (ft_strcmp(STR_SPHERE, block1) == 0))
	{
		if (!check_str_to_double(block3))
			return (FALSE);
	}
	else
	{
		if (!check_str_to_vec3(block3))
			return (FALSE);
	}
	return (TRUE);
}

int			try_find_params_4(char *block1, char *block4)
{
	if (!check_str_to_double(block4))
		return (FALSE);
	return (TRUE);
}

int			try_find_params_5(char *block1, char *block5)
{
	if ((ft_strcmp(STR_CYLINDR, block1) == 0) || (ft_strcmp(STR_CONE, block1) == 0))
	{
		if (!check_str_to_double(block5))
			return (FALSE);
	}
	else
	{
		if (!check_str_to_vec3(block5))
			return (FALSE);
	}
	return (TRUE);
}

int			try_find_params_6(char *block1, char *block6)
{
	if (!check_str_to_vec3(block6))
		return (FALSE);
	return (TRUE);
}

int			check_objs(t_sdl *sdl, char *path)
{
	int		fd;
	char	*tmp;
	char	**split;
	int		white_space_cnt;

	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &tmp) > 0)
	{
		printf("gnl tmp_string_full=%s\n", tmp);
		split = ft_strsplit(tmp, ' ');
		sdl->block_1 = split[0];
		printf("block1==%s==\n", sdl->block_1);
		if (!sdl->block_1 || !try_find_objs(sdl->block_1))
		{
			printf("Wrong object in config file  "); ///////
			return (FALSE);
		}
		white_space_cnt = str_count_c(tmp, ' ');
		if ((ft_strcmp(STR_CAMERA, sdl->block_1) == 0) || (ft_strcmp(STR_LIGHT, sdl->block_1) == 0))
			if (white_space_cnt != 2)
			{
				printf("Wrong number params\n"); ///////
				return (FALSE);
			}
		if ((ft_strcmp(STR_SPHERE, sdl->block_1) == 0) || (ft_strcmp(STR_PLANE, sdl->block_1) == 0))
			if (white_space_cnt != 4)
			{
				printf("Wrong number params\n"); ///////
				return (FALSE);
			}
		if ((ft_strcmp(STR_CONE, sdl->block_1) == 0) || (ft_strcmp(STR_CYLINDR, sdl->block_1) == 0))
			if (white_space_cnt != 5)
			{
				printf("Wrong number params\n"); ///////
				return (FALSE);
			}
		sdl->block_2 = split[1];
		printf("block2==%s==\n", sdl->block_2);
		if (!sdl->block_2 || !try_find_params_2(sdl->block_1, sdl->block_2))
		{
			printf("Wrong parametrs for object"); ///////
			return (FALSE);
		}
		sdl->block_3 = split[2];
		printf("block3==%s==\n", sdl->block_3);
		if (!sdl->block_3 || !try_find_params_3(sdl->block_1, sdl->block_3))
		{
			printf("Wrong parametrs for object"); ///////
			return (FALSE);
		}
		if ((ft_strcmp(STR_CAMERA, sdl->block_1) != 0) && (ft_strcmp(STR_LIGHT, sdl->block_1) != 0))
		{
			sdl->block_4 = split[3];
			printf("block4==%s==\n", sdl->block_4);
			if (!sdl->block_4 || !try_find_params_4(sdl->block_1, sdl->block_4))
			{
				printf("Wrong parametrs for object"); ///////
				return (FALSE);
			}
			sdl->block_5 = split[4];
			printf("block5==%s==\n", sdl->block_5);
			if (!sdl->block_5 || !try_find_params_5(sdl->block_1, sdl->block_5))
			{
				printf("Wrong parametrs for object"); ///////
				return (FALSE);
			}
			if ((ft_strcmp(STR_SPHERE, sdl->block_1) != 0) && (ft_strcmp(STR_PLANE, sdl->block_1) != 0))
			{
				sdl->block_6 = split[5];
				printf("block5==%s==\n", sdl->block_6);
				if (!sdl->block_6 || !try_find_params_6(sdl->block_1, sdl->block_6))
				{
					printf("Wrong parametrs for object"); ///////
					return (FALSE);
				}
			}
		}
		free(tmp);
	}
	close(fd);
	return (TRUE);
}

int			parse_check(t_sdl *sdl, char *path)
{
	int			fd;
	char		*line;
	t_nbr_all	nbrs;
	char		**split;

	nbrs.num_obj = 0;
	nbrs.num_sph = 0;
	nbrs.num_pla = 0;
	nbrs.num_con = 0;
	nbrs.num_cyl = 0;
	nbrs.num_lig = 0;
	nbrs.num_cam = 0;
	printf("Parsing\n");
	if (!(check_objs(sdl, path)))
	{
		printf("bad objects\n");
		return (FALSE);
	}
	printf("___________________________\n");
	printf("next  __parsing_objects and fill them \n");
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		printf("gnl tmp_string_full=%s\n", line);
		split = ft_strsplit(line, ' ');
		sdl->block_1 = split[0];
		if (ft_strcmp(STR_CAMERA, sdl->block_1) == 0)
			nbrs.num_cam++;
		else if (ft_strcmp(STR_LIGHT, sdl->block_1) == 0)
			nbrs.num_lig++;
		else if (ft_strcmp(STR_SPHERE, sdl->block_1) == 0)
			nbrs.num_sph++;
		else if (ft_strcmp(STR_PLANE, sdl->block_1) == 0)
			nbrs.num_pla++;
		else if (ft_strcmp(STR_CONE, sdl->block_1) == 0)
			nbrs.num_con++;
		else if (ft_strcmp(STR_CYLINDR, sdl->block_1) == 0)
			nbrs.num_cyl++;
		else
		{
			printf("error oops\n");
			close(fd);
			free(line);
			return (FALSE);
		}
		free(line);
	}
	close(fd);
	nbrs.num_obj = nbrs.num_sph + nbrs.num_pla + nbrs.num_con + nbrs.num_cyl;
	printf("NBRS cam=%d sphere=%d plane=%d\n", nbrs.num_cam, nbrs.num_sph, nbrs.num_pla);
	printf("NBRS con=%d cylindr=%d light=%d\n", nbrs.num_con, nbrs.num_cyl, nbrs.num_lig);
	printf("ALL=%d\n", nbrs.num_obj);
	if (nbrs.num_cam != 1)
	{
		printf("Error no camera\n");
		return (FALSE);
	}
	if (nbrs.num_obj == 0)
	{
		printf("Error no objects\n");
		return (FALSE);
	}
	sdl->nbrs = nbrs;
	return (TRUE);
}
