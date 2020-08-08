/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objload.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <lomasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 21:27:23 by lomasse           #+#    #+#             */
/*   Updated: 2020/08/08 21:37:57 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ObjReader.h"
#include "../../Includes/ObjError.h"

t_obj       *getobj(t_obj *obj);
int         objerror(int code);

int         objload(char *path)
{
    t_obj   *obj;

    if (!path)
        return (objerror(2));
    obj = getobj(NULL);
    if (!obj)
        return (objerror(3));
    return (0);
}