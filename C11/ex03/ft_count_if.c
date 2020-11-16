/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 07:56:00 by acoudert          #+#    #+#             */
/*   Updated: 2020/10/22 08:00:19 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_if(char **tab, int length, int (*f)(char*))
{
	int		i;
	int		counter;

	counter = 0;
	i = 0;
	while (i < length)
	{
		if ((*f)(tab[i]) != 0)
			counter++;
		i++;
	}
	return (counter);
}
