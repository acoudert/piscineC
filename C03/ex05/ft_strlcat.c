/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 09:44:09 by acoudert          #+#    #+#             */
/*   Updated: 2020/10/16 11:59:15 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	src_len;
	unsigned int	dest_len;
	unsigned int	i;

	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	dest_len = 0;
	while (dest[dest_len] != '\0')
		dest_len++;
	i = 0;
	if (dest_len + 1 > size)
		src_len = src_len + size;
	else
		src_len = src_len + dest_len;
	if (dest_len < size)
		while (src[i] != '\0' && (dest_len + i + 1) < size)
		{
			dest[dest_len + i] = src[i];
			i++;
		}
	dest[dest_len + i] = '\0';
	return (src_len);
}
