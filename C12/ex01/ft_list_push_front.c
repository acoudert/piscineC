/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 06:55:44 by acoudert          #+#    #+#             */
/*   Updated: 2020/10/27 07:08:30 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list		*elem;

	elem = ft_create_elem(data);
	if (*begin_list == 0)
	{
		*begin_list = elem;
		return ;
	}
	elem->next = *begin_list;
	*begin_list = elem;
}
