/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 22:38:44 by luwargni          #+#    #+#             */
/*   Updated: 2020/01/19 22:38:44 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoinfree(char const *dst, char const *src, size_t n)
{
	char	*new;
	int		i;
	int		j;
	int		k;

	if (!dst || !src)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	if (!(new = (char *)malloc(sizeof(char) *
					(ft_strlen(src) + ft_strlen(dst) + 1))))
		return (NULL);
	while (dst[i] || src[j])
	{
		if (dst[i])
			new[k++] = dst[i++];
		else
			new[k++] = src[j++];
	}
	new[k] = '\0';
	n == 1 ? free((void *)dst) : free((void *)src);
	if (n == 3)
		free((void *)dst);
	return (new);
}
