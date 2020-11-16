/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 12:40:37 by acoudert          #+#    #+#             */
/*   Updated: 2020/10/26 09:50:01 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	std_in(t_line *line)
{
	int		bytes_read;
	int		counter;

	line[0].mem_nb = 0;
	bytes_read = 0;
	while ((counter = read(0, line[0].str + bytes_read, 16 - bytes_read)))
	{
		bytes_read += counter;
		if (bytes_read == 16)
		{
			print_line(line, bytes_read);
			line[0].mem_nb += bytes_read;
			bytes_read = 0;
		}
	}
	if (bytes_read > 0 || line[0].mem_nb != 0)
		print_last_lines(line, bytes_read);
}

int		open_file(char *file_name, char *prog_name, t_line *line)
{
	int		fd;

	errno = 0;
	if (open(file_name, O_DIRECTORY) == -1)
	{
		if ((fd = open(file_name, O_RDONLY)) == -1)
		{
			print_err(file_name, prog_name, strerror(errno));
			return (-1);
		}
		else
		{
			line[0].ok_file = 1;
			return (fd);
		}
	}
	else
	{
		line[0].ok_dir = 1;
		print_err(file_name, prog_name, "Is a directory");
	}
	return (-1);
}

int		read_file(t_line *line, int bytes_read, int fd)
{
	int		counter;

	while ((counter = read(fd, line[0].str + bytes_read, 16 - bytes_read)))
	{
		bytes_read += counter;
		if (counter == 0)
			close(fd);
		else if (bytes_read == 16)
		{
			print_line(line, bytes_read);
			line[0].mem_nb += bytes_read;
			bytes_read = 0;
		}
	}
	return (bytes_read);
}

void	files_in(t_line *line, int argc, char *argv[])
{
	int		file_nb;
	int		bytes_read;
	int		fd;

	file_nb = (line[0].mode == 0) ? 1 : 2;
	while (file_nb < argc)
	{
		if ((fd = open_file(argv[file_nb], argv[0], line)) == -1)
		{
			file_nb++;
			continue ;
		}
		bytes_read = (file_nb == line[0].mode + 1) ? 0 : bytes_read;
		bytes_read = read_file(line, bytes_read, fd);
		if (file_nb == argc - 1)
			break ;
		file_nb++;
	}
	if (line[0].mem_nb > 0)
		print_last_lines(line, bytes_read);
	else if (line[0].mem_nb == 0 && line[0].ok_dir == 0 && line[0].ok_file == 0)
		print_err(argv[file_nb - 1], argv[0], "Bad file descriptor");
	else
		print_last_lines(line, bytes_read);
}

void	files_in_caller(t_line *line, int argc, char *argv[])
{
	line[0].mem_nb = 0;
	line[0].ok_file = 0;
	line[0].ok_dir = 0;
	files_in(line, argc, argv);
}
