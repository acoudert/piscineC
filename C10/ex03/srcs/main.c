/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 12:40:37 by acoudert          #+#    #+#             */
/*   Updated: 2020/10/25 17:54:24 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		main(int argc, char *argv[])
{
	t_line		line[2];
	int			i;

	i = 0;
	while (i < 17)
	{
		line[1].str[i] = '\0';
		i++;
	}
	if (argc == 1)
	{
		line[0].mode = 0;
		std_in(line);
	}
	else if (argc >= 2)
	{
		line[0].mode = (ft_strcmp_n(argv[1], "-C", 2) == 0) ? 1 : 0;
		if (line[0].mode == 0)
			files_in_caller(line, argc, argv);
		else if (argc == 2)
			std_in(line);
		else
			files_in_caller(line, argc, argv);
	}
	return (0);
}
