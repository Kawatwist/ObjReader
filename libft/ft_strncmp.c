/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 22:39:15 by luwargni          #+#    #+#             */
/*   Updated: 2020/01/19 22:39:15 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*w;
	unsigned char	*w2;
	int				i;

	if (n == 0)
		return (0);
	w = (unsigned char *)s1;
	w2 = (unsigned char *)s2;
	i = 0;
	while (w[i] == w2[i] && w[i] != '\0' && w2[i] != '\0' && --n > 0)
		i++;
	return (w[i] - w2[i]);
}
