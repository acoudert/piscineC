/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 09:11:21 by acoudert          #+#    #+#             */
/*   Updated: 2020/10/28 11:27:54 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_free_begin(t_list **begin_list, void *data_ref, int (*cmp)(),
void (*free_fct)(void *))
{
	t_list		*elem;

	while ((*cmp)((*begin_list)->data, data_ref) == 0)
	{
		elem = *begin_list;
		*begin_list = (*begin_list)->next;
		(*free_fct)(elem->data);
		free(elem);
		if (*begin_list == 0)
			return ;
	}
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
void (*free_fct)(void *))
{
	t_list		*elem;
	t_list		*temp;

	if (*begin_list == 0)
		return ;
	ft_list_free_begin(begin_list, data_ref, cmp, free_fct);
	elem = *begin_list;
	if (*begin_list == 0)
		return ;
	while (elem->next)
	{
		if ((*cmp)(elem->next->data, data_ref) == 0)
		{
			temp = elem->next->next;
			(*free_fct)(elem->next->data);
			free(elem->next);
			elem->next = temp;
		}
		elem = elem->next;
		if (elem == 0)
			break ;
	}
}
