/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 22:39:36 by luwargni          #+#    #+#             */
/*   Updated: 2020/01/19 22:39:36 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnlen(char *str, int len)
{
	char *ptr;

	ptr = str;
	while (len-- || *str)
		str++;
	return (ptr - str);
}
