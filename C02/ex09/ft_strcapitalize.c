/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:12:07 by acoudert          #+#    #+#             */
/*   Updated: 2020/10/15 18:18:24 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_modif_low_case(char *str, int i)
{
	if (str[i - 1] >= 'a' && str[i - 1] <= 'z')
		return ;
	else if (str[i - 1] >= 'A' && str[i - 1] <= 'Z')
		return ;
	else if (str[i - 1] >= '0' && str[i - 1] <= '9')
		return ;
	else
		str[i] = str[i] - 32;
}

void	ft_modif_up_case(char *str, int i)
{
	if (str[i - 1] >= 'a' && str[i - 1] <= 'z')
		str[i] = str[i] + 32;
	else if (str[i - 1] >= 'A' && str[i - 1] <= 'Z')
		str[i] = str[i] + 32;
	else if (str[i - 1] >= '0' && str[i - 1] <= '9')
		str[i] = str[i] + 32;
}

char	*ft_strcapitalize(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0 && str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
			i++;
			continue;
		}
		if (str[i] >= 'a' && str[i] <= 'z')
			ft_modif_low_case(str, i);
		else if (str[i] >= 'A' && str[i] <= 'Z')
			ft_modif_up_case(str, i);
		i++;
	}
	return (str);
}
