/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 09:31:53 by acoudert          #+#    #+#             */
/*   Updated: 2020/10/15 21:33:38 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		i_to_find;
	int		i_str;

	i_to_find = 0;
	if (to_find[i_to_find] == '\0')
		return (str);
	i_str = 0;
	while (str[i_str] != '\0')
	{
		i_to_find = 0;
		if (str[i_str] == to_find[i_to_find])
		{
			while (str[i_str + i_to_find] == to_find[i_to_find])
			{
				i_to_find++;
				if (to_find[i_to_find] == '\0')
					return (str + i_str);
			}
		}
		i_str++;
	}
	return (0);
}
