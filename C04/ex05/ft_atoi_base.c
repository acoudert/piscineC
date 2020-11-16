/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 12:11:07 by acoudert          #+#    #+#             */
/*   Updated: 2020/10/17 13:53:08 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	base_not_ok(char *base)
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
		else if ((base[i_base1] >= 9 && base[i_base1] <= 13)
				|| base[i_base1] == 32)
			return (1);
		i_base1++;
	}
	return ((i_base1 > 1) ? 0 : 1);
}

int	ft_calculate_int(char *str, char *base, int sign, int i)
{
	int		base_len;
	int		i_base;
	int		res;

	base_len = ft_strlen(base);
	res = 0;
	while (1)
	{
		i_base = 0;
		while (str[i] != base[i_base])
		{
			i_base++;
			if (base[i_base] == 0)
				return (res);
		}
		res *= base_len;
		res = (sign == 1) ? res + i_base : res - i_base;
		i++;
	}
}

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	int		sign;
	int		res;

	if (base_not_ok(base))
		return (0);
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	sign = 1;
	while (str[i] == '+' || str[i] == '-')
	{
		sign = (str[i] == '-') ? sign * (-1) : sign;
		i++;
	}
	res = ft_calculate_int(str, base, sign, i);
	return (res);
}
