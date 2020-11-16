/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 16:44:51 by acoudert          #+#    #+#             */
/*   Updated: 2020/10/19 07:49:56 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_max_sqrt(int nb)
{
	int		low_b;
	int		high_b;
	int		tested_root;

	if (nb < 0)
		return (0);
	if (nb <= 1)
		return (nb);
	low_b = 1;
	high_b = (nb / 2 > 46340) ? 46340 : nb / 2;
	while (low_b <= high_b && low_b <= 46340)
	{
		tested_root = (low_b + high_b) / 2;
		if (tested_root * tested_root > nb)
			high_b = tested_root - 1;
		else if (tested_root * tested_root < nb)
			low_b = tested_root + 1;
		else
			return (tested_root);
	}
	return (tested_root);
}

int		ft_is_prime(int nb)
{
	int		i;
	int		i_max;

	if (nb <= 1)
		return (0);
	i = 2;
	i_max = ft_max_sqrt(nb);
	while (i <= i_max)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	while (!(ft_is_prime(nb)))
		nb++;
	return (nb);
}
