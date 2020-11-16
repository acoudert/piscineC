/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 16:26:00 by acoudert          #+#    #+#             */
/*   Updated: 2020/10/13 18:34:42 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	display_nb(int nb)
{
	char	a;
	char	b;

	a = '0';
	b = '0';
	a = a + nb / 10;
	write(1, &a, 1);
	b = b + nb % 10;
	write(1, &b, 1);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			display_nb(a);
			write(1, " ", 1);
			display_nb(b);
			if (a < 98)
				write(1, ", ", 2);
			b++;
		}
		a++;
	}
}
