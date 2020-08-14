/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objload.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <lomasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 21:27:23 by lomasse           #+#    #+#             */
/*   Updated: 2020/08/14 16:47:51 by lomasse          ###   ########.fr       */
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
    if (obj->flag & TRIANGLE)
        if ((error = triangle(obj)))
            return (error);
    if (obj->flag & REMOVE_DOUBLE)
        if ((error = remove_double(obj)))
            return (error);
    return (0);
}