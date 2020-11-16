/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 11:44:13 by acoudert          #+#    #+#             */
/*   Updated: 2020/10/23 11:02:02 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/errno.h>
# include <libgen.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_strlen(char *str);
int		not_number(char *str);
void	err_out(char *program_name, char *error, char *str);
void	err_out_mem(char *program_name);
int		ft_atoi(char *str);
void	std_in(char *program_name, int nb);
void	ft_banner(char *file_name, int *file_nb);
void	ft_display(char *str, int nb_bytes, int counter);
void	read_file(int nb_files, char **argv, int i, int *file_nb);

#endif
