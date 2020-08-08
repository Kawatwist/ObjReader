/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 22:35:56 by luwargni          #+#    #+#             */
/*   Updated: 2020/01/19 22:35:57 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*str;
	char	*str2;
	int		i;

	i = 0;
	str = (char *)dst;
	str2 = (char *)src;
	if (str > str2 && (str2 + len) > str)
		while (len-- > 0)
			str[len] = str2[len];
	else
		while (len-- != 0)
		{
			*str = *str2;
			str++;
			str2++;
		}
	return (dst);
}
