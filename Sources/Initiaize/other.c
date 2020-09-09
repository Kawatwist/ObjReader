/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <lomasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 20:07:31 by lomasse           #+#    #+#             */
/*   Updated: 2020/08/16 17:37:41 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ObjReader.h"

t_obj       *getobj(t_obj *obj)
{
    static t_obj    *save = NULL;
    t_obj           *tmp;
    int             nb;
    
    if (((int)obj & INDEX))
    {
        nb = ((unsigned int)obj) >> 6;
        tmp = save;
        while (tmp && nb--)
            tmp = tmp->next;
        return (tmp);
    }
    if (obj == (t_obj *)0x1 && save)
        save = NULL;
    else if (obj == (void *)(MEMORY))
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
        tmp = save;
        while (tmp->next != NULL)
            tmp = tmp->next;
        if (!(tmp->next = ft_memalloc(sizeof(t_obj))))
            return (NULL); // Should Return FreeObj
        return (tmp->next);
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