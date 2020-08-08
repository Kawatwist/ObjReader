/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 22:35:29 by luwargni          #+#    #+#             */
/*   Updated: 2020/01/19 22:35:32 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*str;
	const unsigned char	*str2;
	unsigned char		c2;

	str = (unsigned char *)dst;
	str2 = (const unsigned char *)src;
	c2 = (unsigned char)c;
	while (n)
	{
		*str = *str2;
		if (*str++ == c2)
			return (str);
		str2++;
		n--;
	}
	return (NULL);
}
