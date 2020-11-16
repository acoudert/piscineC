/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 16:27:51 by acoudert          #+#    #+#             */
/*   Updated: 2020/10/19 07:35:59 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
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
	return (0);
}
