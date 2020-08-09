/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <lomasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 20:55:57 by lomasse           #+#    #+#             */
/*   Updated: 2020/08/09 16:46:57 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ObjReader.h"
#include "../Includes/ObjError.h"

int         objload(char *path);

t_obj       *getobj(t_obj *obj)
{
    static t_obj *save = NULL;
    
    if (save == NULL && obj)
        save = obj;
    else if (save != NULL && obj != NULL)
    {
        printf("Do not send obj to this function to get obj pointeur\n");
        return (NULL);
    }
    return (save);
}

int         objerror(t_obj *obj, int code)
{
    static char    *tab[] = {ERR_OBJ_VALID, ERR_OBJ_MALLOC, ERR_OBJ_OPEN, ERR_OBJ_NOT_INIT, 
                        ERR_OBJ_PARSING,ERR_OBJ_INVALID};

	code >= ERR_MAX ? code = ERR_MAX - 1: 0;
	code < 0 ? code = ERR_MAX - 1 : 0;
    if (code == 4)
        printf("Error line : %ld\n", obj->line);
    printf("%s", tab[code]);
    return (code);
}

int         main(int argc, char **argv)
{
    t_obj   obj;

    if (init_obj(&obj) == -1)
        return (objerror(&obj, -1));
    if (argc < 2 || argc > 2)
        return (objerror(&obj, 2));
    objload(argv[1]);
    return (0);
}