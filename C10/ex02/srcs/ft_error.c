/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 07:09:15 by acoudert          #+#    #+#             */
/*   Updated: 2020/10/23 11:01:02 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	err_out(char *program_name, char *error, char *str)
{
	write(2, basename(program_name), ft_strlen(basename(program_name)));
	if (error[0] == 'M')
		write(2, ": option requires an argument -- c\n", 35);
	else if (error[0] == 'N')
	{
		write(2, ": illegal offset -- ", 20);
		write(2, str, ft_strlen(str));
		write(2, "\n", 1);
	}
	else if (error[0] == 'F')
	{
		write(2, ": ", 2);
		write(2, str, ft_strlen(str));
		write(2, ": ", 2);
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		write(2, "\n", 1);
	}
}

void	err_out_mem(char *program_name)
{
	write(2, basename(program_name), ft_strlen(basename(program_name)));
	write(2, ": malloc: ", 10);
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
}
