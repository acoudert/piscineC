/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 12:41:13 by acoudert          #+#    #+#             */
/*   Updated: 2020/10/26 11:35:12 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <libgen.h>
# include <string.h>
# include <sys/errno.h>

typedef struct		s_line
{
	unsigned int	mem_nb;
	char			str[17];
	char			str_hex[49];
	int				repeated;
	int				mode;
	int				ok_file;
	int				ok_dir;
}					t_line;

char				*ft_strcpy_n(char *dest, char *src, int bytes_read);
int					ft_strcmp_n(char *s1, char *s2, int n);
int					ft_strlen(char *str);
char				*ft_strcat(char *dest, char *src);
char				*int_to_hex(unsigned int nb, int str_size);
void				str_to_hex(t_line *line, int n);
void				print_str(t_line *line, int n);
void				repeated_line(t_line *line);
void				print_line(t_line *line, int n);
void				print_last_lines(t_line *line, int bytes_read);
void				std_in(t_line *line);
void				print_err(char *file_name, char *program_name, char *error);
int					open_file(char *file_name, char *prog_name, t_line *line);
int					read_file(t_line *line, int bytes_read, int fd);
void				files_in(t_line *line, int argc, char *argv[]);
void				files_in_caller(t_line *line, int argc, char *argv[]);

#endif
