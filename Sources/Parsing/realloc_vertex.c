/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_vertex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <lomasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 22:48:16 by lomasse           #+#    #+#             */
/*   Updated: 2020/08/09 19:43:40 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ObjReader.h"

static char     *ft_ralloc(char **str, long int newsize)
{
	char *res;

	if (!(res = ft_strnew(newsize)))
		return (0);
	res = ft_memcpy(res, *str, newsize / 2);
	ft_memdel((void **)str);
    return (res);
}
void         *realloc_vertex(t_obj *obj, char type, void    **dest)
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
    else
        return (NULL);
    return (ft_ralloc((char **)(dest), size));
}