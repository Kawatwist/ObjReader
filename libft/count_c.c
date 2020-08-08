/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 22:33:32 by luwargni          #+#    #+#             */
/*   Updated: 2020/01/19 22:33:34 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		count_c(char *src, char c)
{
	unsigned int		size;

	size = 0;
	while (*src)
		if (*src++ == c)
			size++;
	return (size);
}
