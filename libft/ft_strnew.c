/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 22:39:31 by luwargni          #+#    #+#             */
/*   Updated: 2020/01/19 22:39:31 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = NULL;
	size++;
	if (!(str = (char *)malloc(sizeof(char) * (int)size)))
		return (NULL);
	while (size != 0)
	{
		str[size] = '\0';
		size--;
	}
	str[0] = '\0';
	return (str);
}
