/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 22:37:13 by luwargni          #+#    #+#             */
/*   Updated: 2020/01/19 22:37:13 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_straddline(char *str, char c)
{
	int		len;
	char	*pos;
	char	*tmp;
	char	*newhead;

	if (!(pos = ft_strchr(str, c)))
		return (NULL);
	len = pos - str;
	if (len < 1 || !(tmp = ft_strndup(str, len + 1))
			|| !(newhead = ft_strndup(pos + 1, ft_strlen(pos))))
		return (NULL);
	free(str);
	str = ft_strjoinfree(newhead, tmp, 3);
	return (str);
}
