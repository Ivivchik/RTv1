/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 20:16:37 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/12 10:37:15 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_mater   mater_new(void)
{
  t_mater  new_mater;

  new_mater.type_mat = NULL;
  new_mater.albedo = vec_new(0.0, 0.0, 0.0);
  new_mater.diff_col = vec_new(0.0, 0.0, 0.0);
  new_mater.spec_exp = 0.0;
  return (new_mater);
}

void      mater_fill(t_mater *mat, char *mat_type)
{
  if (!(ft_strcmp(mat_type, MAT_IVORY)))
    fill_mat_ivory(mat);
  else if (!(ft_strcmp(mat_type, MAT_RED_RUBBER)))
    fill_mat_red_rub(mat);
  else if (!(ft_strcmp(mat_type, MAT_MIRROR)))
    fill_mat_mirror(mat);
  else if (!(ft_strcmp(mat_type, MAT_METAL)))
    fill_mat_metal(mat);
  else if (!(ft_strcmp(mat_type, MAT_LAMBERT)))
    fill_mat_lambert(mat);
  return ;
}
