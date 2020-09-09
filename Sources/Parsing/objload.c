/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objload.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <lomasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 21:27:23 by lomasse           #+#    #+#             */
/*   Updated: 2020/08/16 17:52:57 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ObjReader.h"

int         triangle(t_obj *obj)
{
    printf("Triangle working on progress\n");
    return (0);
}

int         remove_double(t_obj *obj)
{
    printf("Remove double working on progress\n");
    return (0);
}

void        find_max_face(t_obj *obj)
{
    t_group *ptr;

    ptr = obj->group;
    while (ptr)
    {
        obj->size_face[0] += ptr->size_face[0];
        obj->size_face[1] += ptr->size_face[1];
        ptr = ptr->next;
    }
}

int         objload(char *path, int flag)
{
    t_obj   *obj;
    int     error;

    if (!path)
        return (objerror(obj, 2));
    obj = getobj((void *)0);
    if (!obj)
        return (objerror(obj, 3));
    obj->path = ft_strdup(path);
    obj->flag = flag;
    if ((error = main_parser(obj)))
        return (error);
    find_max_face(obj);
    if (obj->flag & TRIANGLE)
        if ((error = triangle(obj)))
            return (error);
    if (obj->flag & REMOVE_DOUBLE)
        if ((error = remove_double(obj)))
            return (error);
    if (obj->mtlib)
    {
        ft_strstr(path, ".obj")[0] = '\0';
        obj->mtl = mtlparser(ft_strjoin(path,".mtl"));
    }
    while (1)
        printf("ASDASD\n");
    return (0);
}