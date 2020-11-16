/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 10:05:18 by acoudert          #+#    #+#             */
/*   Updated: 2020/10/27 10:57:34 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list		*elem;
	void		*temp;
	int			swap;

	elem = *begin_list;
	if (elem == 0)
		return ;
	while (elem->next)
	{
		swap = 0;
		if ((*cmp)(elem->data, elem->next->data) > 0)
		{
			temp = elem->data;
			elem->data = elem->next->data;
			elem->next->data = temp;
			swap = 1;
		}
		if (swap == 1)
			elem = *begin_list;
		else
			elem = elem->next;
	}
}
