/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <lomasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 21:54:34 by lomasse           #+#    #+#             */
/*   Updated: 2020/08/08 23:11:12 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ObjReader.h"
#include "../../Includes/ObjError.h"
#include "../../libft/get_next_line.h"
#include <fcntl.h>

int         objerror(int code);
int     parsing_vertex(t_obj *obj, char *line);

int            init_v_malloc(t_obj *obj)
{
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

int             main_parser(t_obj *obj)
{
    char    *line;
    int     fd;

    fd = open(obj->path, O_RDONLY);
    if (fd == -1)
        return (objerror(2));
    if (init_v_malloc(obj))
        return (1);
    while (get_next_line(fd, &line))
    {
        printf("%s\n", line);
        if (line[0] == 'v')
            if (parsing_vertex(obj, line))
                return (-1);
        printf("DONE\n");
        free(line);
    }
    free(line);
        printf("DONE\n");
    return (0);
}