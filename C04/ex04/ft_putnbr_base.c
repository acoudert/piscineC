/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 09:11:03 by acoudert          #+#    #+#             */
/*   Updated: 2020/10/17 12:09:55 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		base_not_ok(char *base)
{
	int		i_base1;
	int		i_base2;

	i_base1 = 0;
	while (base[i_base1])
	{
		i_base2 = 0;
		while (i_base2 < i_base1)
		{
			if (base[i_base1] == base[i_base2])
				return (1);
			i_base2++;
		}
		if (base[i_base1] == '+' || base[i_base1] == '-')
			return (1);
		i_base1++;
	}
	return ((i_base1 > 1) ? 0 : 1);
}

int		ft_res_tab(char *res, char *base, int nbr, int base_len)
{
	int		i;

	i = 31;
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
			write(1, "-", 1);
		}
		res[i] = base[nbr % base_len];
		nbr = nbr / base_len;
		if (nbr == 0)
			break ;
		i--;
	}
	return (i);
}

void	ft_display_res(char *res, int i)
{
	while (i < 32)
	{
		write(1, res + i, 1);
		i++;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	char	res[32];
	int		base_len;
	int		i;

	if (base_not_ok(base))
		return ;
	base_len = ft_strlen(base);
	i = ft_res_tab(res, base, nbr, base_len);
	ft_display_res(res, i);
}
