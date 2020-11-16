/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 17:15:30 by acoudert          #+#    #+#             */
/*   Updated: 2020/10/17 17:38:23 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_display_board(char *board)
{
	int		x_pos;

	x_pos = 0;
	while (x_pos <= 9)
	{
		write(1, board + x_pos, 1);
		x_pos++;
	}
	write(1, "\n", 1);
}

int		abs_value(int a, int b)
{
	if (a > b)
		return (a - b);
	else
		return (b - a);
}

int		pos_is_safe(char *board, int x_pos)
{
	int		i;

	i = 0;
	while (i < x_pos)
	{
		if (board[i] == board[x_pos])
			return (0);
		if (abs_value(i, x_pos) == abs_value(board[i], board[x_pos]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_solve_queens(char *board, int x_pos, int *solution_nb)
{
	board[x_pos] = '0';
	while (board[x_pos] <= '9')
	{
		if (pos_is_safe(board, x_pos))
		{
			if (x_pos == 9)
			{
				ft_display_board(board);
				*solution_nb = *solution_nb + 1;
			}
			else
				ft_solve_queens(board, x_pos + 1, solution_nb);
		}
		board[x_pos] = board[x_pos] + 1;
	}
}

int		ft_ten_queens_puzzle(void)
{
	int		solution_nb;
	char	board[10];
	int		x_pos;

	x_pos = 0;
	solution_nb = 0;
	ft_solve_queens(board, x_pos, &solution_nb);
	return (solution_nb);
}
