/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddlline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 22:37:17 by luwargni          #+#    #+#             */
/*   Updated: 2020/01/19 22:37:18 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strnrchr(char *str, int c)
{
	int	i;
	int oc;

	i = ft_strlen(str);
	oc = 0;
	while (i)
	{
		if (str[i] == c)
			oc++;
		if (oc == 2)
			return (&str[i]);
		i -= 1;
	}
	if (i == 0 && str[i] != c)
		return (NULL);
	return (&str[i]);
}

char		*ft_straddlline(char *str, char c)
{
	int		len;
	char	*pos;
	char	*tmp;
	char	*newhead;

	if (!(pos = ft_strnrchr(str, c)))
		return (NULL);
	len = pos - str;
	if (len < 1
			|| !(tmp = ft_strndup(pos + 1, ft_strlen(pos + 1)))
			|| !(newhead = ft_strndup(str, len + 1)))
		return (NULL);
	free(str);
	str = ft_strjoinfree(tmp, newhead, 3);
	return (str);
}
