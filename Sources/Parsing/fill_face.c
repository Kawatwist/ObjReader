/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_face.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <lomasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 16:00:45 by lomasse           #+#    #+#             */
/*   Updated: 2020/08/09 17:56:09 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ObjReader.h"
#include "../../Includes/ObjError.h"
#include "../../libft/get_next_line.h"
#include <fcntl.h>

static char     *ft_ralloc(char **str, long int newsize)
{
	char *res;

	if (!(res = ft_strnew(newsize)))
		return (0);
	res = ft_memcpy(res, *str, newsize / 2);
	ft_memdel((void **)str);
    return (res);
}

void         *realloc_face(t_obj *obj, void    **dest)
{
    long int    size;
 
    size = obj->size_face[1] * sizeof(t_face);
    return (ft_ralloc((char **)(dest), size));
}

int         find_next(char *line, int i);

int         allocate_index(t_obj *obj, int nb_index)
{
    obj->face[obj->size_face[0]].size = nb_index;
    if (!(obj->face[obj->size_face[0]].i_v = malloc((sizeof(int) * nb_index) * 3)))
        return (1);
    ft_bzero(obj->face[obj->size_face[0]].i_v, (sizeof(int) * nb_index) * 3);
    obj->face[obj->size_face[0]].i_vt = &(obj->face[obj->size_face[0]].i_v[nb_index]);
    obj->face[obj->size_face[0]].i_vn = &(obj->face[obj->size_face[0]].i_vt[nb_index]);
    return (0);
}

int         find_next(char *line, int i);

int         get_index(char *line, int *i, int (*index)[3], int nb, t_face *f)
{
    int j;

    if (nb == 0)
    {
        f->flag = 0;
        j = find_next(line, *i);
        while (line[j] && !ft_isspace(line[j]))
        {
            if (line[j] == '/')
                f->flag++;
            if (f->flag >= 3)
                return (4);
            j++;
        }
    }
    (*index)[0] = 0;
    (*index)[1] = 0;
    (*index)[2] = 0;
    *i = find_next(line, *i);
    (*index)[0] = ft_atoi(&(line[*i]));
    while (line[*i] && (line[*i] != '/' && !ft_isspace(line[*i])))
        (*i)++;
    if (f->flag == 0)
        return (0);
    else if (!line[*i])
        return (4);
    else if (ft_isspace(line[*i]))
        return (4);
    (*i)++;
    (*index)[1] = ft_atoi(&(line[*i]));
    while (line[*i] && (line[*i] != '/' && !ft_isspace(line[*i])))
        (*i)++;
    if (f->flag == 1)
        return (0);
    else if (!line[*i])
        return (4);
    else if (ft_isspace(line[*i]))
        return (4);
    (*i)++;
    (*index)[2] = ft_atoi(&(line[*i]));
    return (0);
}

int         fill_index_face(t_obj *obj, char *line)
{
    int     index[3];
    int     i;
    int     nb;
    int     error;
    
    i = 0;
    nb = 0;
    while (nb < obj->face[obj->size_face[0]].size)
    {
        if ((error = get_index(line, &i, &(index), nb, &obj->face[obj->size_face[0]])))
            return (error);
        obj->face[obj->size_face[0]].i_v[nb] = index[0];
        obj->face[obj->size_face[0]].i_vt[nb] = index[1];
        obj->face[obj->size_face[0]].i_vn[nb] = index[2];
        nb++;
    }
    return (0);
}

int         fill_face(t_obj *obj, char *line)
{
    int     nb_index;
    int     i;
    int     error;

    i = 0;
    i = find_next(line, i);
    nb_index = 0;
    while (line[i])
    {
        i = find_next(line, i);
        nb_index++;
    }
    if (nb_index < 3)
    {
        printf("Incorrect Face (%s)\n", line);
        return (4);
    }
    if (allocate_index(obj, nb_index))
        return (1);
    if ((error = fill_index_face(obj, line)))
        return (error);
    return (0);
}

int         parsing_face(t_obj *obj, char *line)
{
    int error;

    if ((error = fill_face(obj, line)))
        return (error);
    obj->size_face[0] += 1;
    if (obj->size_face[0] == obj->size_face[1])
    {
        obj->size_face[1] *= 2;
        if (!(obj->face = realloc_face(obj, (void **)(&obj->face))))
            return (1);
    }
    return (0);
}