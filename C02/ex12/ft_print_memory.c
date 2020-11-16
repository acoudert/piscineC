/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 07:42:46 by acoudert          #+#    #+#             */
/*   Updated: 2020/10/18 08:40:17 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	print_mem_hex(void *addr)
{
	unsigned long	addr_val;
	char			*tab_conv;
	char			tab_res[16];
	int				i;

	addr_val = (unsigned long)addr;
	tab_conv = "0123456789abcdef";
	i = 15;
	while (i != 0)
	{
		tab_res[i] = tab_conv[addr_val % 16];
		addr_val = addr_val / 16;
		i--;
	}
	tab_res[i] = tab_conv[addr_val % 16];
	while (i <= 15)
	{
		write(1, tab_res + i, 1);
		i++;
	}
	write(1, ": ", 2);
}

void	print_str_in_hex(char *str, unsigned int size)
{
	unsigned int		i;
	char				a;
	char				b;
	char				*tab_conv;

	tab_conv = "0123456789abcdef";
	i = 0;
	while (i < size)
	{
		a = tab_conv[str[i] / 16];
		b = tab_conv[str[i] % 16];
		write(1, &a, 1);
		write(1, &b, 1);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
	if (size != 16)
	{
		while (i < 16)
		{
			write(1, " ", 1);
			i++;
		}
	}
}

void	print_str(char *str, unsigned int size, unsigned int total_size)
{
	unsigned int		i;

	i = 0;
	while (i < size)
	{
		if (str[i] == 32 && i < total_size && i > 0)
		{
			if (str[i - 1] == ' ')
			{
				i++;
				continue;
			}
			else
				write(1, str + i, 1);
		}
		else if (str[i] >= 32 && str[i] != 127)
			write(1, str + i, 1);
		else
			write(1, ".", 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	char			*ptr;

	ptr = (char*)addr;
	i = 0;
	while (i < size)
	{
		print_mem_hex(ptr + i);
		if (size > i + 16)
		{
			print_str_in_hex(ptr + i, 16);
			print_str(ptr + i, 16, size);
		}
		else
		{
			print_str_in_hex(ptr + i, size - i);
			print_str(ptr + i, size - i, size);
		}
		write(1, "\n", 1);
		i = i + 16;
	}
	return (addr);
}
