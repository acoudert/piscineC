/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 08:10:38 by acoudert          #+#    #+#             */
/*   Updated: 2020/10/22 09:07:55 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>

typedef void			(*t_operation)(int, int);
typedef struct			s_op
{
	char			op_type;
	t_operation		op_ft;
}						t_op;

int						ft_strlen(char *str);
int						ft_operator_not_ok(char *op);
void					ft_set_up_struct(t_op *op_struct);
int						ft_atoi(char *str);
void					ft_putnbr(int nb);
void					ft_do_op(char *argv[], t_op *op_struct);
void					ft_addition(int a, int b);
void					ft_substraction(int a, int b);
void					ft_division(int a, int b);
void					ft_multiplication(int a, int b);
void					ft_modulo(int a, int b);

#endif
