/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 22:37:08 by luwargni          #+#    #+#             */
/*   Updated: 2020/01/19 22:37:09 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_realloc(char *s, size_t n)
{
	char	*str;

	str = NULL;
	if (n > ft_strlen(s))
		return (NULL);
	str = ft_strdup(&s[n]);
	free(s);
	return (str);
}
