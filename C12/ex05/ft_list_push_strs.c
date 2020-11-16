/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 07:29:31 by acoudert          #+#    #+#             */
/*   Updated: 2020/10/27 07:36:30 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list		*ft_list_push_strs(int size, char **strs)
{
	int			i;
	t_list		*list;
	t_list		*elem;

	list = 0;
	i = 0;
	while (i < size)
	{
		elem = list;
		list = ft_create_elem(strs[i]);
		list->next = elem;
		i++;
	}
	return (list);
}
