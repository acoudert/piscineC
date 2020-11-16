/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 08:50:31 by acoudert          #+#    #+#             */
/*   Updated: 2020/10/22 08:50:38 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_addition(int a, int b)
{
	ft_putnbr(a + b);
}

void	ft_substraction(int a, int b)
{
	ft_putnbr(a - b);
}

void	ft_division(int a, int b)
{
	if (b == 0)
	{
		write(1, "Stop : division by zero", 23);
		return ;
	}
	ft_putnbr(a / b);
}

void	ft_multiplication(int a, int b)
{
	ft_putnbr(a * b);
}

void	ft_modulo(int a, int b)
{
	if (b == 0)
	{
		write(1, "Stop : modulo by zero", 21);
		return ;
	}
	ft_putnbr(a % b);
}
