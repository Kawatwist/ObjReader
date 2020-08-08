/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 22:39:11 by luwargni          #+#    #+#             */
/*   Updated: 2020/01/19 22:39:11 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnchr(const char *s, int c, size_t n)
{
	size_t		i;
	size_t		j;
	char		*ret;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	ret = (char *)s;
	while (ret[i] && j < n)
	{
		if (ret[i] == c)
		{
			j++;
		}
		i++;
	}
	if (j == n)
		return (&ret[i]);
	return (NULL);
}
