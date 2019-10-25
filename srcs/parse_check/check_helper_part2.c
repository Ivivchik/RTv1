/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_helper_part2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 22:17:08 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/25 03:04:25 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			check_str_to_hex(char *block)
{
	if (ft_strlen(block) == 6)
	{
		if (check_letter_hex(block))
		{
			return (TRUE);
		}
	}
	return (FALSE);
}

int			check_str_to_double(char *block)
{
	char		**str_double;
	char		*double_b_zero;

	str_double = ft_strsplit(block, '.');
	if (str_double[0])
		double_b_zero = ft_strsub(str_double[0], 1,
		ft_strlen(str_double[0]) - 1);
	if (str_count_c(block, '.') == 0)
	{
		if (str_double[0] &&
				(check_letter_num(str_double[0]) ||
				(check_letter_num(double_b_zero) && str_double[0][0] == '-')))
			return (free_split_double_true(&str_double, &double_b_zero));
	}
	if (str_count_c(block, '.') == 1)
	{
		if (str_double[0] && str_double[1] &&
				check_letter_num(str_double[1]) &&
				(check_letter_num(str_double[0]) ||
				(check_letter_num(double_b_zero) && str_double[0][0] == '-')))
			return (free_split_double_true(&str_double, &double_b_zero));
	}
	ft_putstr("bad double");
	return (free_split_double_false(&str_double, &double_b_zero));
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
			return (free_split_vec3_true(&str_vec));
	}
	ft_putstr("bad vector");
	return (FALSE);
}

t_nbr_all	nbr(void)
{
	t_nbr_all	nbrs;

	nbrs.num_obj = 0;
	nbrs.num_sph = 0;
	nbrs.num_pla = 0;
	nbrs.num_con = 0;
	nbrs.num_cyl = 0;
	nbrs.num_lig = 0;
	nbrs.num_cam = 0;
	nbrs.num_amb = 0;
	return (nbrs);
}
