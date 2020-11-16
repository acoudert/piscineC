/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 08:03:30 by acoudert          #+#    #+#             */
/*   Updated: 2020/10/27 08:45:37 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list		*prev;
	t_list		*next;

	if (*begin_list == 0)
		return ;
	prev = 0;
	next = *begin_list;
	while ((*begin_list)->next)
	{
		next = (*begin_list)->next;
		(*begin_list)->next = prev;
		prev = (*begin_list);
		(*begin_list) = next;
	}
	(*begin_list)->next = prev;
}
