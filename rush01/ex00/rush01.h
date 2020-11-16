/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 14:49:38 by souassin          #+#    #+#             */
/*   Updated: 2020/10/25 14:49:41 by souassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <stdlib.h>
# include <unistd.h>

void	tab_input(char **tab, char *argv[]);
char	**set_up_tab(char *argv[]);
int		ft_strlen(char *str);
int		input_str_not_ok(char *input);
int		input_not_ok(int argc, char *argv[]);
int		no_x_repeated(char **tab, int x, int y);
int		no_y_repeated(char **tab, int x, int y);
int		safe_left(char **tab, int y);
int		safe_right(char **tab, int y);
int		safe_top(char **tab, int x);
int		safe_bot(char **tab, int x);
void	print_tab(char **tab);
void	solve_tab(char **tab, int x, int y, int *stop);
void	free_tab(char **tab);

#endif
