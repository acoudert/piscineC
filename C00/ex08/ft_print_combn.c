/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 17:28:49 by acoudert          #+#    #+#             */
/*   Updated: 2020/10/13 18:13:30 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_tab_setup(char *tab, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		tab[i] = i;
		i++;
	}
	while (i < 10)
	{
		tab[i] = 10;
		i++;
	}
}

void	ft_tab_display(char *tab)
{
	int		i;
	char	c;

	i = 0;
	while (tab[i] != 10)
	{
		c = tab[i] + '0';
		write(1, &c, 1);
		i++;
	}
}

int		ft_index_to_incr(char *tab, int size)
{
	while (tab[size - 1] == tab[size] - 1)
		size--;
	return (size - 1);
}

void	ft_update_tab(char *tab, int i)
{
	tab[i] = tab[i] + 1;
	i++;
	while (tab[i] != 10)
	{
		tab[i] = tab[i - 1] + 1;
		i++;
	}
}

void	ft_print_combn(int n)
{
	char	tab[10];
	int		i_to_increase;

	ft_tab_setup(tab, n);
	while (tab[0] != 10 - n)
	{
		ft_tab_display(tab);
		if (tab[0] != 10 - n)
			write(1, ", ", 2);
		i_to_increase = ft_index_to_incr(tab, n);
		ft_update_tab(tab, i_to_increase);
	}
	ft_tab_display(tab);
}
