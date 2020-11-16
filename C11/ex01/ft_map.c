/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 07:36:47 by acoudert          #+#    #+#             */
/*   Updated: 2020/10/22 07:44:21 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int		i;
	int		*tab_res;

	tab_res = (int*)malloc(sizeof(int) * length);
	if (tab_res == 0)
		return (0);
	i = 0;
	while (i < length)
	{
		tab_res[i] = (*f)(tab[i]);
		i++;
	}
	return (tab_res);
}
