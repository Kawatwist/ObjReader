/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <lomasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 21:54:34 by lomasse           #+#    #+#             */
/*   Updated: 2020/08/09 17:57:24 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ObjReader.h"
#include "../../Includes/ObjError.h"
#include "../../libft/get_next_line.h"
#include <fcntl.h>

int         objerror(t_obj *obj, int code);
int         parsing_vertex(t_obj *obj, char *line);
int         parsing_face(t_obj *obj, char *line);

int            init_v_malloc(t_obj *obj)
{
    obj->size_face[0] = 0;
    obj->size_face[1] = 64;
    if (!(obj->face = malloc(sizeof(t_face) * 64)))
        return (1);
    obj->size_v[0] = 0;
    obj->size_v[1] = 64;
    if (!(obj->v = malloc(sizeof(t_vertex4) * 64)))
        return (1);
    ft_memset(obj->v, 0, sizeof(t_vertex4) * 64);
    obj->size_vn[0] = 0;
    obj->size_vn[1] = 64;
    if (!(obj->vn = malloc(sizeof(t_vertex) * 64)))
        return (1);
    ft_memset(obj->vn, 0, sizeof(t_vertex) * 64);
    obj->size_vt[0] = 0;
    obj->size_vt[1] = 64;
    if (!(obj->vt = malloc(sizeof(t_vertex) * 64)))
        return (1);
    ft_memset(obj->vt, 0, sizeof(t_vertex) * 64);
    obj->size_vp[0] = 0;
    obj->size_vp[1] = 64;
    if (!(obj->vp = malloc(sizeof(t_vertex) * 64)))
        return (1);
    ft_memset(obj->vp, 0, sizeof(t_vertex) * 64);
    return (0);
}

int             adjust_allocation(t_obj *obj)
{
    return (0);
}

int             main_parser(t_obj *obj)
{
    char    *line;
    char    *new;
    int     fd;
    int     error;

    fd = open(obj->path, O_RDONLY);
    if (fd == -1)
        return (objerror(obj, 2));
    if (init_v_malloc(obj))
        return (objerror(obj, 1));
    obj->line = 1;
    while (get_next_line(fd, &line))
    {
        new = skip_whitespace(line);
        if (new == NULL || !new[0])
           ;
        else if (new[0] == 'v')
        {
            if ((error = parsing_vertex(obj, new)))
                return (objerror(obj, error));
        }
        else if (new[0] == 'f')
        {
            if ((error = parsing_face(obj, new)))
                return (objerror(obj, error));
        }
        else if (new[0] == '#')
            ;
        else if (new[0] == 'o')
            ;
        else if (new[0] == 'm')
            ;
        else
        {
            printf("==> %s\n", new);
            return (objerror(obj, 4));
        }
        line != NULL ? free(line) : 0;
        obj->line++;
    }
    line ? free(line) : 0;
    printf("Min : %f\t\t%f\t\t%f\n", obj->min.x, obj->min.y, obj->min.z);
    printf("Max : %f\t\t%f\t\t%f\n", obj->max.x, obj->max.y, obj->max.z);
    obj->center.x = (obj->min.x + obj->max.x / 2.0);
    obj->center.y = (obj->min.y + obj->max.y / 2.0);
    obj->center.z = (obj->min.z + obj->max.z / 2.0);
    printf("Center : %f\t\t%f\t\t%f\n", obj->center.x, obj->center.y, obj->center.z);
    printf("Il y a :\n");
    printf("\t\t. %ld\t\t= v~\t\t%ld\t(Mallocated)\n", obj->size_v[0], obj->size_v[1]);
    printf("\t\t. %ld\t\t= vt\t\t%ld\t(Mallocated)\n", obj->size_vt[0], obj->size_vt[1]);
    printf("\t\t. %ld\t\t= vn\t\t%ld\t(Mallocated)\n", obj->size_vn[0], obj->size_vn[1]);
    printf("\t\t. %ld\t\t= vp\t\t%ld\t(Mallocated)\n", obj->size_vp[0], obj->size_vp[1]);
    printf("\t\t. %ld\t\t= f~\t\t%ld\t(Mallocated)\n", obj->size_face[0], obj->size_face[1]);
    printf("%s : DONE\n", obj->path);
    return (0);
}