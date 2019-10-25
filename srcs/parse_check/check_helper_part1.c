/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_helper_part1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 22:16:56 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/25 02:17:44 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			str_count_c(char *str, char c)
{
	int		count;
	int		i;
	int		len;

	count = 0;
	if (str)
	{
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

int			is_hex(int c)
{
	return (int)(((c >= 'a' && c <= 'f') || (c >= '0' && c <= '9')) ? 1 : 0);
}

int			check_letter_hex(char *str)
{
	int		i;
	int		len;

	len = ft_strlen(str);
	i = -1;
	while (++i < len)
	{
		if (!(is_hex(ft_tolower(str[i]))))
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
