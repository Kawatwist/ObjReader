/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 22:38:57 by luwargni          #+#    #+#             */
/*   Updated: 2020/01/19 22:38:57 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlen(const char *str)
{
	int		i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		if ((unsigned int)str[i + 1] == 0x00)
			return (i + 1);
		if ((unsigned int)str[i + 2] == 0x00)
			return (i + 2);
		if ((unsigned int)str[i + 3] == 0x00)
			return (i + 3);
		i += 4;
	}
	return (i);
}
