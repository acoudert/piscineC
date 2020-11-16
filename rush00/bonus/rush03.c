/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 08:31:26 by acoudert          #+#    #+#             */
/*   Updated: 2020/10/18 13:35:16 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TOP_LEFT		'A'
#define TOP_RIGHT		'C'
#define BOT_LEFT		'A'
#define BOT_RIGHT		'C'
#define HORIZ_LINE		'B'
#define CENTER			' '
#define VERTI_LINE		'B'

void	ft_putchar(char c);

void	ft_display_line(int width, char left, char center, char right)
{
	int		col_nb;

	if (width > 0)
		ft_putchar(left);
	col_nb = 2;
	while (col_nb < width)
	{
		ft_putchar(center);
		col_nb++;
	}
	if (col_nb == width)
		ft_putchar(right);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int		line_nb;

	if (x > 0 && y > 0)
		ft_display_line(x, TOP_LEFT, HORIZ_LINE, TOP_RIGHT);
	line_nb = 2;
	while (x > 0 && line_nb < y)
	{
		ft_display_line(x, VERTI_LINE, CENTER, VERTI_LINE);
		line_nb++;
	}
	if (x > 0 && line_nb == y)
		ft_display_line(x, BOT_LEFT, HORIZ_LINE, BOT_RIGHT);
}
