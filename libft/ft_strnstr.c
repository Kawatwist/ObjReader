/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 22:39:40 by luwargni          #+#    #+#             */
/*   Updated: 2020/01/19 22:39:40 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t			lensrc;
	char			*dest;
	char			*src;

	dest = (char *)haystack;
	src = (char *)needle;
	lensrc = ft_strlen(src);
	while (*dest && len >= lensrc)
	{
		if (ft_memcmp(dest, src, lensrc) == 0)
			return (dest);
		dest++;
		len--;
	}
	return (NULL);
}
