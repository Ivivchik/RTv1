/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_metal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 01:42:36 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/12 01:45:57 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void      fill_mat_metal(t_mater *mat)
{
  mat->type_mat = ft_strdup(MAT_METAL);
  mat->albedo = vec_new(0.8, 0.6, 0.2);
  mat->diff_col = vec_new(1.0, 1.0, 1.0);
  mat->spec_exp = 20.0;
  return ;
}
