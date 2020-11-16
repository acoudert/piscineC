/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 10:35:26 by acoudert          #+#    #+#             */
/*   Updated: 2020/10/27 10:52:43 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		ft_fun_set_up(t_list **elem)
{
	int		size;

	size = 1;
	while ((*elem)->next)
	{
		size++;
		*elem = (*elem)->next;
	}
	return (size);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list		*elem;
	t_list		*running_elem;
	void		*temp;
	int			size;
	int			i;

	if (begin_list == 0)
		return ;
	elem = begin_list;
	size = ft_fun_set_up(&elem);
	i = 0;
	while (i < size / 2)
	{
		temp = begin_list->data;
		begin_list->data = elem->data;
		elem->data = temp;
		running_elem = begin_list;
		while (running_elem->next != elem)
			running_elem = running_elem->next;
		elem = running_elem;
		begin_list = begin_list->next;
		i++;
	}
}
