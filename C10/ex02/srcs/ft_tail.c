/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:38:16 by acoudert          #+#    #+#             */
/*   Updated: 2020/10/25 12:53:07 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	std_in(char *program_name, int nb)
{
	int		bytes_read;
	char	*str;
	int		counter;
	int		offset;

	str = (char*)malloc(sizeof(char) * nb);
	if (str == 0)
		err_out_mem(program_name);
	counter = 0;
	if (nb == 0)
		while (read(0, str, 1) > 0)
			continue ;
	else
	{
		while ((bytes_read = read(0, str, nb)) > 0)
			counter += bytes_read;
		if (counter >= nb)
		{
			offset = counter % nb;
			write(1, str + offset, nb - offset);
			write(1, str, offset);
		}
		else
			write(1, str, counter);
	}
}

void	ft_banner(char *file_name, int *file_nb)
{
	if (*file_nb != 1)
		write(1, "\n", 1);
	write(1, "==> ", 4);
	write(1, file_name, ft_strlen(file_name));
	write(1, " <==", 4);
	write(1, "\n", 1);
	*file_nb = *file_nb + 1;
}

void	ft_display(char *str, int nb_bytes, int counter)
{
	int		offset;

	if (counter >= nb_bytes)
	{
		offset = counter % nb_bytes;
		write(1, str + offset, nb_bytes - offset);
		write(1, str, offset);
	}
	else
		write(1, str, counter);
}

void	read_file(int nb_files, char **argv, int i, int *file_nb)
{
	int		fd;
	int		bytes_read;
	char	*str;
	int		counter;

	errno = 0;
	if ((fd = open(argv[i], O_RDONLY)) == -1)
	{
		err_out(argv[0], "File", argv[i]);
		return ;
	}
	str = (char*)malloc(sizeof(char) * (ft_atoi(argv[2])));
	if (str == 0)
	{
		err_out_mem(argv[0]);
		return ;
	}
	counter = 0;
	while ((bytes_read = read(fd, str, ft_atoi(argv[2]))) > 0)
		counter += bytes_read;
	if (nb_files > 1)
		ft_banner(argv[i], file_nb);
	ft_display(str, ft_atoi(argv[2]), counter);
	free(str);
	close(fd);
}
