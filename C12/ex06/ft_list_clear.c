/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 07:37:41 by acoudert          #+#    #+#             */
/*   Updated: 2020/10/27 11:20:47 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list		*temp;

	while (begin_list)
	{
		temp = begin_list;
		begin_list = begin_list->next;
		(*free_fct)(temp->data);
		free(temp);
	}
}
