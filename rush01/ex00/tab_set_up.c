/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_set_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 12:15:56 by souassin          #+#    #+#             */
/*   Updated: 2020/10/25 14:40:18 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	tab_input(char **tab, char *argv[])
{
	tab[1][0] = argv[1][0];
	tab[2][0] = argv[1][2];
	tab[3][0] = argv[1][4];
	tab[4][0] = argv[1][6];
	tab[1][5] = argv[1][8];
	tab[2][5] = argv[1][10];
	tab[3][5] = argv[1][12];
	tab[4][5] = argv[1][14];
	tab[0][1] = argv[1][16];
	tab[0][2] = argv[1][18];
	tab[0][3] = argv[1][20];
	tab[0][4] = argv[1][22];
	tab[5][1] = argv[1][24];
	tab[5][2] = argv[1][26];
	tab[5][3] = argv[1][28];
	tab[5][4] = argv[1][30];
}

char	**set_up_tab(char *argv[])
{
	int		i;
	char	**tab;

	tab = (char**)malloc(sizeof(char*) * 6);
	if (tab == 0)
		return (0);
	i = 0;
	while (i < 6)
	{
		tab[i] = (char*)malloc(sizeof(char*) * 6);
		if (tab[i] == 0)
			return (0);
		i++;
	}
	tab_input(tab, argv);
	return (tab);
}
