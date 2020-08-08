/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_vertex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <lomasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 22:48:16 by lomasse           #+#    #+#             */
/*   Updated: 2020/08/08 23:10:04 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ObjReader.h"
#include "../../Includes/ObjError.h"

static int		ft_ralloc(char **str, long int newsize)
{
	char *res;

	if (!(res = ft_strdup(*str)))
		return (0);
	ft_memdel((void**)str);
	if (!(*str = ft_strnew(newsize)))
		return (0);
	*str = ft_memcpy(*str, res, newsize / 2);
	ft_memdel((void **)&res);
	return (1);
}

void         *realloc_vertex(t_obj *obj, char type, void    *dest)
{
    long int    size;
 
    if (!type)
        size = obj->size_v[1] * sizeof(t_vertex4);
    else if (type == 1)
        size = obj->size_vt[1] * sizeof(t_vertex);
    else if (type == 2)
        size = obj->size_vn[1] * sizeof(t_vertex);
    else if (type == 3)
        size = obj->size_vp[1] * sizeof(t_vertex);
    if (!(ft_ralloc((char **)(&dest), size)))
        return (NULL);
    return ((void *)0x1);
}