/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 12:38:49 by acoudert          #+#    #+#             */
/*   Updated: 2020/10/26 09:51:08 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	print_str(t_line *line, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		if (line[0].str[i] >= 32 && line[0].str[i] <= 126)
			write(1, &(line[0].str[i]), 1);
		else
			write(1, ".", 1);
		i++;
	}
}

void	repeated_line(t_line *line)
{
	if (line[1].repeated == 0)
	{
		write(1, "*\n", 2);
		line[1].repeated = 1;
	}
}

void	print_line(t_line *line, int bytes_read)
{
	int		mem_nb_length;

	mem_nb_length = (line[0].mode == 0) ? 7 : 8;
	line[0].str[bytes_read] = '\0';
	if (ft_strcmp_n(line[0].str, line[1].str, bytes_read) == 0)
		repeated_line(line);
	else
	{
		write(1, int_to_hex(line[0].mem_nb, mem_nb_length), mem_nb_length);
		write(1, " ", 1);
		if (line[0].mode == 1)
			write(1, " ", 1);
		str_to_hex(line, bytes_read);
		write(1, line[0].str_hex, ft_strlen(line[0].str_hex));
		if (line[0].mode == 1)
		{
			write(1, "  |", 3);
			print_str(line, bytes_read);
			write(1, "|", 1);
		}
		write(1, "\n", 1);
		ft_strcpy_n(line[1].str, line[0].str, bytes_read);
		line[1].repeated = 0;
	}
}

void	print_err(char *file_name, char *program_name, char *error)
{
	write(2, basename(program_name), ft_strlen(basename(program_name)));
	write(2, ": ", 2);
	write(2, basename(file_name), ft_strlen(basename(file_name)));
	write(2, ": ", 2);
	write(2, error, ft_strlen(error));
	write(2, "\n", 1);
}

void	print_last_lines(t_line *line, int bytes_read)
{
	if (bytes_read > 0)
	{
		print_line(line, bytes_read);
		line[0].mem_nb += bytes_read;
	}
	if (line[0].mode == 0 && line[0].mem_nb != 0)
	{
		write(1, int_to_hex(line[0].mem_nb, 7), 7);
		write(1, "\n", 1);
	}
	else if (line[0].mode == 1 && line[0].mem_nb != 0)
	{
		write(1, int_to_hex(line[0].mem_nb, 8), 8);
		write(1, "\n", 1);
	}
}
