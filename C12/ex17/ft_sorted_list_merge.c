/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 11:02:44 by acoudert          #+#    #+#             */
/*   Updated: 2020/10/28 08:20:45 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

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

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
int (*cmp)())
{
	t_list		*elem;

	if (*begin_list1 == 0)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	if (begin_list2 == 0)
		return ;
	elem = *begin_list1;
	while (elem->next)
		elem = elem->next;
	elem->next = begin_list2;
	list_sort_elem(begin_list1, cmp);
}
