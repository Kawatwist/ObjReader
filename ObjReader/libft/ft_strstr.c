/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 22:39:52 by luwargni          #+#    #+#             */
/*   Updated: 2020/01/19 22:39:53 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*ret;
	int		i;
	int		len;

	ret = (char *)haystack;
	len = ft_strlen(needle);
	i = 0;
	while (i < len && *ret != '\0')
	{
		if (*ret == needle[i])
			i++;
		else if (i > 0)
		{
			ret -= (i - 1);
			i = 0;
		}
		ret++;
	}
	if (i < len)
		return (NULL);
	return (ret - i);
}
