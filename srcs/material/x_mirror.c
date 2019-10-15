/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_mirror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 01:42:36 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/12 01:45:31 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void      fill_mat_mirror(t_mater *mat)
{
  mat->type_mat = ft_strdup(MAT_MIRROR);
  mat->albedo = vec_new(0.0, 10.0, 0.8);
  mat->diff_col = vec_new(1.0, 1.0, 1.0);
  mat->spec_exp = 1425.0;
  return ;
}
