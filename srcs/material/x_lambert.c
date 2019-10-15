/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_lambert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 01:42:36 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/12 01:47:11 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void      fill_mat_lambert(t_mater *mat)
{
  mat->type_mat = ft_strdup(MAT_LAMBERT);
  mat->albedo = vec_new(0.8, 0.3, 0.0);
  mat->diff_col = vec_new(1.0, 1.0, 1.0);
  mat->spec_exp = 100.0;
  return ;
}
