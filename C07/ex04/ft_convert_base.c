/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:40:37 by acoudert          #+#    #+#             */
/*   Updated: 2020/10/19 18:07:01 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_atoi_base(char *str, char *base);
int		base_not_ok(char *base);
int		ft_strlen(char *str);

int		ft_res_tab(char *res, char *base, int nbr, int base_len)
{
	int		i;

	i = 32;
	res[0] = '0';
	while (1)
	{
		if (nbr < 0)
		{
			if (nbr == -2147483648)
			{
				res[i] = base[(nbr % base_len) * (-1)];
				nbr = nbr / base_len;
				i--;
			}
			nbr = (-1) * nbr;
			res[0] = '-';
		}
		res[i] = base[nbr % base_len];
		nbr = nbr / base_len;
		if (nbr == 0)
			break ;
		i--;
	}
	return (i);
}

int		ft_putnbr_base(int nbr, char *base, char *res)
{
	int		base_len;
	int		i;

	base_len = ft_strlen(base);
	i = ft_res_tab(res, base, nbr, base_len);
	return (i);
}

char	*res_str_alloc(char *res_tab, int i)
{
	char	*res_str;
	int		nb_of_char;

	nb_of_char = (res_tab[0] == '-') ? 33 - i + 1 : 33 - i;
	res_str = (char*)malloc(sizeof(char) * nb_of_char);
	return (res_str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*res_str;
	char	res_tab[33];
	int		i;
	int		j;

	if (base_not_ok(base_from) || base_not_ok(base_to))
		return (0);
	i = ft_putnbr_base(ft_atoi_base(nbr, base_from), base_to, res_tab);
	res_str = res_str_alloc(res_tab, i);
	j = 0;
	if (res_tab[0] == '-')
	{
		res_str[0] = '-';
		j++;
	}
	while (i < 33)
	{
		res_str[j] = res_tab[i];
		i++;
		j++;
	}
	res_str[j] = '\0';
	return (res_str);
}
