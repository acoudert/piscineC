/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 11:18:27 by acoudert          #+#    #+#             */
/*   Updated: 2020/10/21 15:25:20 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_display(char *file_name)
{
	int		fd;
	int		read_bytes;
	char	c[1];

	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (0);
	while ((read_bytes = read(fd, c, 1)) && read_bytes != -1)
		write(1, c, 1);
	close(fd);
	return (1);
}

int		main(int argc, char *argv[])
{
	if (argc < 2)
		write(2, "File name missing.\n", 19);
	else if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	else if (ft_display(argv[1]) == 0)
		write(2, "Cannot read file.\n", 18);
	return (0);
}
