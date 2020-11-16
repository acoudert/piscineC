/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 21:03:33 by acoudert          #+#    #+#             */
/*   Updated: 2020/10/13 21:11:51 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int		i;
	int		temporary;

	i = 0;
	while (i < size / 2)
	{
		temporary = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = temporary;
		i++;
	}
}
