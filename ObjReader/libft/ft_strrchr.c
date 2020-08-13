/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 22:39:44 by luwargni          #+#    #+#             */
/*   Updated: 2020/01/19 22:39:44 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;
	int		i;

	i = ft_strlen(s);
	ret = (char *)s;
	while (i)
	{
		if (ret[i] == c)
			return (&ret[i]);
		i--;
	}
	if (i == 0 && ret[i] != c)
		return (NULL);
	return (&ret[i]);
}
