/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 22:38:02 by luwargni          #+#    #+#             */
/*   Updated: 2020/01/19 22:38:02 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdupfree(char **str, char c)
{
	char *new;

	new = ft_strdup(ft_strchr(*str, c) + 1);
	if (new)
		free(*str);
	return (new);
}
