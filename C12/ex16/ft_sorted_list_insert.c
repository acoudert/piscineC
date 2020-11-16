/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 10:53:59 by acoudert          #+#    #+#             */
/*   Updated: 2020/10/28 08:19:12 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	list_add_elem_front(t_list **begin_list, void *data)
{
	t_list		*element;

	element = ft_create_elem(data);
	if (*begin_list == 0)
	{
		*begin_list = element;
		return ;
	}
	element->next = *begin_list;
	*begin_list = element;
}

void	list_sort_elem(t_list **begin_list, int (*cmp)())
{
	t_list		*element;
	void		*temporary;
	int			swap_check;

	element = *begin_list;
	if (element == 0)
		return ;
	while (element->next)
	{
		swap_check = 0;
		if ((*cmp)(element->data, element->next->data) > 0)
		{
			temporary = element->data;
			element->data = element->next->data;
			element->next->data = temporary;
			swap_check = 1;
		}
		if (swap_check == 1)
			element = *begin_list;
		else
			element = element->next;
	}
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	list_add_elem_front(begin_list, data);
	list_sort_elem(begin_list, cmp);
}
