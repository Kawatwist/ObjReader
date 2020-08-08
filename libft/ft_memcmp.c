/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 22:35:41 by luwargni          #+#    #+#             */
/*   Updated: 2020/01/19 22:35:42 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *str;
	unsigned char *str2;

	str = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n)
	{
		if (*str != *str2)
			return (*str - *str2);
		str++;
		str2++;
		n--;
	}
	return (0);
}
