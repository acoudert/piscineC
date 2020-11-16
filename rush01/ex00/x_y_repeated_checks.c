/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_y_repeated_checks.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 12:16:05 by souassin          #+#    #+#             */
/*   Updated: 2020/10/25 14:40:31 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int		no_x_repeated(char **tab, int x, int y)
{
	int		i;

	i = 1;
	while (i < x)
	{
		if (tab[i][y] == tab[x][y])
			return (0);
		i++;
	}
	return (1);
}

int		no_y_repeated(char **tab, int x, int y)
{
	int		i;

	i = 1;
	while (i < y)
	{
		if (tab[x][i] == tab[x][y])
			return (0);
		i++;
	}
	return (1);
}
