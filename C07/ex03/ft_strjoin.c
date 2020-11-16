/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 09:59:13 by acoudert          #+#    #+#             */
/*   Updated: 2020/10/20 07:49:45 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strcpy_from_i(char *dest, char *src, int i_dest)
{
	int		i_src;

	i_src = 0;
	while (src[i_src] != 0)
	{
		dest[i_dest + i_src] = src[i_src];
		i_src++;
	}
	dest[i_dest + i_src] = src[i_src];
}

int		ft_total_len(int size, char **strs, char *sep)
{
	int		i;
	int		total_len;

	total_len = 0;
	i = 0;
	while (i < size)
	{
		total_len += ft_strlen(strs[i]);
		if (i < size - 1)
			total_len += ft_strlen(sep);
		i++;
	}
	return (total_len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i_str;
	int		i_final;
	int		total_len;
	char	*final_str;

	total_len = ft_total_len(size, strs, sep);
	final_str = (char*)malloc(sizeof(char) * total_len + 1);
	if (final_str == 0)
		return (0);
	i_str = 0;
	i_final = 0;
	while (i_str < size)
	{
		ft_strcpy_from_i(final_str, strs[i_str], i_final);
		i_final += ft_strlen(strs[i_str]);
		if (i_str < size - 1)
		{
			ft_strcpy_from_i(final_str, sep, i_final);
			i_final += ft_strlen(sep);
		}
		i_str++;
	}
	return (final_str);
}
