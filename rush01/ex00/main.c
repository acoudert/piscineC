/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 12:15:46 by souassin          #+#    #+#             */
/*   Updated: 2020/10/25 14:40:08 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	print_tab(char **tab)
{
	int		x;
	int		y;

	y = 1;
	while (y < 5)
	{
		x = 1;
		while (x < 5)
		{
			write(1, &(tab[x][y]), 1);
			if (x < 4)
				write(1, " ", 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}

void	solve_tab(char **tab, int x, int y, int *stop)
{
	tab[x][y] = '1';
	while (tab[x][y] < '5' && !(*stop))
	{
		if (no_x_repeated(tab, x, y) && no_y_repeated(tab, x, y))
		{
			if (x < 4 && y < 4)
				solve_tab(tab, x + 1, y, stop);
			else if (x == 4 && safe_left(tab, y) && safe_right(tab, y))
			{
				if (y < 4)
					solve_tab(tab, 1, y + 1, stop);
				else if (y == 4 && safe_top(tab, x) && safe_bot(tab, x))
				{
					(*stop)++;
					print_tab(tab);
				}
			}
			else if (x < 4 && y == 4 && safe_top(tab, x) && safe_bot(tab, x))
				solve_tab(tab, x + 1, y, stop);
		}
		tab[x][y]++;
	}
}

void	free_tab(char **tab)
{
	int		i;

	i = 0;
	while (i < 6)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int		main(int argc, char *argv[])
{
	char	**tab;
	int		stop;

	if (input_not_ok(argc, argv))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	stop = 0;
	tab = set_up_tab(argv);
	if (tab == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	solve_tab(tab, 1, 1, &stop);
	if (stop == 0)
		write(1, "Error\n", 6);
	free_tab(tab);
	return (0);
}
