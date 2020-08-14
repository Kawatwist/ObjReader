/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <lomasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 20:07:31 by lomasse           #+#    #+#             */
/*   Updated: 2020/08/14 13:59:31 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ObjReader.h"

t_obj       *getobj(t_obj *obj)
{
    static t_obj *save = NULL;
    t_obj *tmp;
    
    if (obj == (t_obj *)0x1 && save)
        save = NULL;
    else if (obj == (void *)0x1)
    {
        printf("FreeObj Asked with Obj in memory\n");
        return (NULL);
    }
    if (save == NULL && obj)
        save = obj;
    else if (save != NULL && obj != NULL)
    {
        printf("Send Null to this function to get obj pointeur\n");
        return (NULL);
    }
    if (save->path)
    {
        while (save->next != NULL)
            save = save->next;
        if (!(save->next = ft_memalloc(sizeof(t_obj))))
            return (NULL); // Should Return FreeObj
        return (save->next);
    }
    if (obj == (void *)(UNINDEX))
    {
        tmp = save;
        save = NULL;
        return (tmp);
    }
    return (save);
}

int         objerror(t_obj *obj, int code)
{
    static char    *tab[] = {ERR_OBJ_VALID, ERR_OBJ_MALLOC, ERR_OBJ_OPEN, ERR_OBJ_NOT_INIT, 
                        ERR_OBJ_PARSING,ERR_OBJ_INVALID};

	code >= ERR_MAX ? code = ERR_MAX - 1: 0;
	code < 0 ? code = ERR_MAX - 1 : 0;
    if (code == 4 || code == 1)
        printf("Error line : %ld\n", obj->line);
    printf("%s", tab[code]);
    return (code);
}