/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objload.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <lomasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 21:27:23 by lomasse           #+#    #+#             */
/*   Updated: 2020/08/09 16:45:38 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ObjReader.h"
#include "../../Includes/ObjError.h"

t_obj       *getobj(t_obj *obj);
int         objerror(t_obj *obj, int code);
int         main_parser(t_obj *obj);

int         objload(char *path)
{
    t_obj   *obj;

    if (!path)
        return (objerror(obj, 2));
    obj = getobj(NULL);
    if (!obj)
        return (objerror(obj, 3));
    obj->path = path;
    if (main_parser(obj))
        return (4);
    return (0);
}