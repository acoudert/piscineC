/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 09:55:36 by acoudert          #+#    #+#             */
/*   Updated: 2020/10/27 10:04:31 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list		*elem;

	if (*begin_list1 == 0)
		*begin_list1 = begin_list2;
	else
	{
		elem = *begin_list1;
		while (elem->next)
			elem = elem->next;
		elem->next = begin_list2;
	}
}
