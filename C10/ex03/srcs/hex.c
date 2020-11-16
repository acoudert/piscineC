/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 12:38:02 by acoudert          #+#    #+#             */
/*   Updated: 2020/10/26 11:34:54 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*int_to_hex(unsigned int nb, int str_size)
{
	int		i;
	char	*base;
	char	*str;

	base = "0123456789abcdef";
	str = (char*)malloc(sizeof(char) * (str_size + 1));
	if (str == 0)
		return (0);
	if (nb >= 268435456 && str_size == 7)
		str_size++;
	i = str_size - 1;
	while (i > 0)
	{
		str[i] = base[nb % 16];
		nb = nb / 16;
		i--;
	}
	str[i] = base[nb % 16];
	str[str_size] = '\0';
	return (str);
}

void	str_to_hex(t_line *line, int n)
{
	int		i;
	char	*char_in_hex;

	line[0].str_hex[0] = '\0';
	i = 0;
	while (i < n)
	{
		char_in_hex = int_to_hex((unsigned char)line[0].str[i], 2);
		ft_strcat(line[0].str_hex, char_in_hex);
		if (i < 16 - 1)
			ft_strcat(line[0].str_hex, " ");
		if (line[0].mode == 1 && i == 7)
			ft_strcat(line[0].str_hex, " ");
		i++;
	}
	while (i < 16)
	{
		ft_strcat(line[0].str_hex, "  ");
		if (i < 16 - 1)
			ft_strcat(line[0].str_hex, " ");
		if (line[0].mode == 1 && i == 7)
			ft_strcat(line[0].str_hex, " ");
		i++;
	}
}
