/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 08:12:22 by acoudert          #+#    #+#             */
/*   Updated: 2020/10/21 08:12:25 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		find_next_i_str(char *str, char *charset)
{
	int		i_str;
	int		i_set;

	i_str = 0;
	while (str[i_str] != '\0')
	{
		i_set = 0;
		while (charset[i_set] != '\0')
		{
			if (str[i_str] == charset[i_set])
				break ;
			i_set++;
		}
		if (charset[i_set] == '\0')
			return (i_str);
		i_str++;
	}
	return (i_str);
}

int		find_next_i_set(char *str, char *charset)
{
	int		i_str;
	int		i_set;

	i_str = 0;
	while (str[i_str] != '\0')
	{
		i_set = 0;
		while (charset[i_set] != '\0')
		{
			if (str[i_str] == charset[i_set])
				return (i_str);
			i_set++;
		}
		i_str++;
	}
	return (i_str);
}

int		ft_nb_of_strs(char *str, char *charset)
{
	int		res;
	int		i;

	res = 0;
	i = 0;
	while (str[i] != '\0')
	{
		i += find_next_i_str(str + i, charset);
		if (str[i] == '\0')
			break ;
		res++;
		i += find_next_i_set(str + i, charset);
	}
	return (res);
}

void	ft_alloc_cpy_str(char *str, char *charset, char **splitted, int i_ptr)
{
	int		i;
	int		i_end;

	i = 0;
	i_end = find_next_i_set(str, charset);
	splitted[i_ptr] = (char*)malloc(sizeof(char) * (i_end - i) + 1);
	while (i < i_end)
	{
		splitted[i_ptr][i] = str[i];
		i++;
	}
	splitted[i_ptr][i] = '\0';
}

char	**ft_split(char *str, char *charset)
{
	char	**splitted;
	int		nb_of_strs;
	int		i_ptr;
	int		i;

	nb_of_strs = ft_nb_of_strs(str, charset);
	splitted = (char**)malloc(sizeof(char*) * nb_of_strs + 1);
	if (splitted == 0)
		return (0);
	i_ptr = 0;
	i = 0;
	while (i_ptr < nb_of_strs)
	{
		i += find_next_i_str(str + i, charset);
		if (str[i] == '\0')
			break ;
		ft_alloc_cpy_str(str + i, charset, splitted, i_ptr);
		i += find_next_i_set(str + i, charset);
		i_ptr++;
	}
	splitted[i_ptr] = 0;
	return (splitted);
}
