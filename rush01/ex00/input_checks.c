/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 12:14:57 by souassin          #+#    #+#             */
/*   Updated: 2020/10/25 15:18:39 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		input_str_not_ok(char *input)
{
	int		i;
	int		counter;

	counter = 0;
	i = 0;
	while (i < ft_strlen(input))
	{
		if (input[i] < '1' || input[i] > '4')
			return (1);
		if ((counter < 15 && input[i + 1] == ' ') || input[i + 1] == '\0')
		{
			i = i + 2;
			counter++;
		}
		else
			return (1);
	}
	if (counter != 16)
		return (1);
	return (0);
}

int		input_not_ok(int argc, char *argv[])
{
	if (argc != 2)
		return (1);
	if (input_str_not_ok(argv[1]))
		return (1);
	return (0);
}
