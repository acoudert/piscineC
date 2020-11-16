/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 11:47:53 by acoudert          #+#    #+#             */
/*   Updated: 2020/10/25 14:58:13 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

void	std_in(void)
{
	int		bytes_read;
	char	c[1];

	while ((bytes_read = read(0, c, 1)))
		write(1, &c, 1);
}

void	err_out(char *file_name, char *type, char *program_name)
{
	write(2, basename(program_name), ft_strlen(basename(program_name)));
	write(2, ": ", 2);
	if (type[0] == 'D')
	{
		write(2, file_name, ft_strlen(file_name));
		write(2, "/: Is a directory\n", 18);
	}
	else if (type[0] == 'F')
	{
		write(2, file_name, ft_strlen(file_name));
		write(2, ": ", 2);
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		write(2, "\n", 1);
	}
}

void	read_file(char *file_name, char *program_name)
{
	int		fd;
	int		read_bytes;
	char	c[1];

	if (open(file_name, O_DIRECTORY) == -1)
	{
		if ((fd = open(file_name, O_RDONLY)) == -1)
			err_out(file_name, "File", program_name);
		else
			while ((read_bytes = read(fd, c, 1)))
			{
				if (read_bytes == -1)
					err_out(file_name, "File", program_name);
				else
					write(1, &c, 1);
			}
		close(fd);
	}
	else
		err_out(file_name, "Directory", program_name);
}

int		main(int argc, char *argv[])
{
	int		i;

	i = 1;
	if (argc == 1)
		std_in();
	else
	{
		while (i < argc)
		{
			read_file(argv[i], argv[0]);
			i++;
		}
	}
}
