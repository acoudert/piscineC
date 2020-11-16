/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_column_checks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 12:15:15 by souassin          #+#    #+#             */
/*   Updated: 2020/10/25 14:39:42 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int		safe_left(char **tab, int y)
{
	int		highest_box;
	int		x;
	int		nb_box_seen;

	nb_box_seen = '0';
	highest_box = '0';
	x = 1;
	while (x < 5)
	{
		if (tab[x][y] > highest_box)
		{
			nb_box_seen++;
			highest_box = tab[x][y];
		}
		x++;
	}
	if (nb_box_seen == tab[0][y])
		return (1);
	return (0);
}

int		safe_right(char **tab, int y)
{
	int		highest_box;
	int		x;
	int		nb_box_seen;

	nb_box_seen = '0';
	highest_box = '0';
	x = 4;
	while (x > 0)
	{
		if (tab[x][y] > highest_box)
		{
			nb_box_seen++;
			highest_box = tab[x][y];
		}
		x--;
	}
	if (nb_box_seen == tab[5][y])
		return (1);
	return (0);
}

int		safe_top(char **tab, int x)
{
	int		highest_box;
	int		y;
	int		nb_box_seen;

	nb_box_seen = '0';
	highest_box = '0';
	y = 1;
	while (y < 5)
	{
		if (tab[x][y] > highest_box)
		{
			nb_box_seen++;
			highest_box = tab[x][y];
		}
		y++;
	}
	if (nb_box_seen == tab[x][0])
		return (1);
	return (0);
}

int		safe_bot(char **tab, int x)
{
	int		highest_box;
	int		y;
	int		nb_box_seen;

	nb_box_seen = '0';
	highest_box = '0';
	y = 4;
	while (y > 0)
	{
		if (tab[x][y] > highest_box)
		{
			nb_box_seen++;
			highest_box = tab[x][y];
		}
		y--;
	}
	if (nb_box_seen == tab[x][5])
		return (1);
	return (0);
}
