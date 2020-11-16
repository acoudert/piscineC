/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 08:14:42 by acoudert          #+#    #+#             */
/*   Updated: 2020/10/22 09:02:05 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_set_up_struct(t_op *op_struct)
{
	op_struct[0].op_type = '+';
	op_struct[0].op_ft = &ft_addition;
	op_struct[1].op_type = '-';
	op_struct[1].op_ft = &ft_substraction;
	op_struct[2].op_type = '/';
	op_struct[2].op_ft = &ft_division;
	op_struct[3].op_type = '*';
	op_struct[3].op_ft = &ft_multiplication;
	op_struct[4].op_type = '%';
	op_struct[4].op_ft = &ft_modulo;
}

void	ft_do_op(char *argv[], t_op *op_struct)
{
	int		nb1;
	int		nb2;
	int		i;

	nb1 = ft_atoi(argv[1]);
	nb2 = ft_atoi(argv[3]);
	i = 0;
	while (op_struct[i].op_type != argv[2][0])
		i++;
	op_struct[i].op_ft(nb1, nb2);
}

int		main(int argc, char *argv[])
{
	t_op	op_struct[5];

	if (argc != 4)
		return (0);
	else if (ft_operator_not_ok(argv[2]))
	{
		write(1, "0\n", 2);
		return (0);
	}
	ft_set_up_struct(op_struct);
	ft_do_op(argv, op_struct);
	write(1, "\n", 1);
	return (0);
}
