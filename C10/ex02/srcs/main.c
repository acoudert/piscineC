/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 19:33:06 by acoudert          #+#    #+#             */
/*   Updated: 2020/10/23 10:40:21 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		main(int argc, char *argv[])
{
	int		i;
	int		file_nb;

	file_nb = 1;
	i = 3;
	if (argc == 2)
		err_out(argv[0], "Missing arguments", "Whatever");
	else if (not_number(argv[2]))
		err_out(argv[0], "Not number", argv[2]);
	else if (argc == 3)
		std_in(argv[0], ft_atoi(argv[2]));
	else
	{
		while (i < argc)
		{
			read_file(argc - 3, argv, i, &file_nb);
			i++;
		}
	}
	return (0);
}
