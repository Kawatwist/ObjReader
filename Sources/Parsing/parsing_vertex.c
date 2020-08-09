/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_vertex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <lomasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 22:08:52 by lomasse           #+#    #+#             */
/*   Updated: 2020/08/09 16:44:15 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ObjReader.h"
#include "../../Includes/ObjError.h"

void         *realloc_vertex(t_obj *obj, char type, void    *dest);

static char    find_type(char  *line)
{
    if (line[1] == ' ' || line[1] == '\t' || line[1] == '\f')
        return (0);
    else if (line[1] == 't')
        return (1);
    else if (line[1] == 'n')
        return (2);
    else if (line[1] == 'p')
        return (3);
    return (-1);
}

static int      check_realloc(t_obj *obj, char type)
{
    if (!type)
    {
        obj->size_v[0] += 1;
        if (obj->size_v[0] == obj->size_v[1])
        {
           obj->size_v[1] *= 2;
           if (!(obj->v = realloc_vertex(obj, type, &obj->v)))
            return (1);
        }
    }
    else if (type == 1)
    {
        obj->size_vt[0] += 1;
        if (obj->size_vt[0] == obj->size_vt[1])
        {
           obj->size_vt[1] *= 2;
           if (!(obj->vt = realloc_vertex(obj, type, &obj->vt)))
            return (1);
        }
    }
    else if (type == 2)
    {
        obj->size_vn[0] += 1;
        if (obj->size_vn[0] == obj->size_vn[1])
        {
           obj->size_vn[1] *= 2;
           if (!(obj->vn = realloc_vertex(obj, type, &obj->vn)))
            return (1);
        }
    }
    else if (type == 3)
    {
        obj->size_vp[0] += 1;
        if (obj->size_vp[0] == obj->size_vp[1])
        {
           obj->size_vp[1] *= 2;
           if (!(obj->vp = realloc_vertex(obj, type, &obj->vp)))
            return (1);
        }
    }
    return (0);
}

int         fill_vertex(t_obj *obj, char *line, char type);

int             parsing_vertex(t_obj *obj, char *line)
{
    char    type;
    int     error;

    type = find_type(line);
    if (type == -1)
        return (-1);
    if ((error = fill_vertex(obj, line, type)))
        return (error);
    if ((check_realloc(obj, type)))
        return (1);
    return (0);
}