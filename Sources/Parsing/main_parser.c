/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <lomasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 21:54:34 by lomasse           #+#    #+#             */
/*   Updated: 2020/08/08 22:06:17 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ObjReader.h"
#include "../../Includes/ObjError.h"
#include "../../libft/get_next_line.h"
#include <fcntl.h>

int         objerror(int code);

void            fill_fake_value(t_obj *obj)
{
    obj->size_v = 4;
    obj->v = malloc(sizeof(t_vertex4) * 4);
    ft_memset(obj->v, 0, sizeof(t_vertex4) * 4);
    obj->size_vn = 4;
    obj->vn = malloc(sizeof(t_vertex) * 4);
    ft_memset(obj->vn, 0, sizeof(t_vertex) * 4);
    obj->size_vt = 4;
    obj->vt = malloc(sizeof(t_vertex) * 4);
    ft_memset(obj->vt, 0, sizeof(t_vertex) * 4);
    obj->size_vp = 4;
    obj->vp = malloc(sizeof(t_vertex) * 4);
    ft_memset(obj->vp, 0, sizeof(t_vertex) * 4);
}

int             main_parser(t_obj *obj)
{
    char    *line;
    int     fd;

    fd = open(obj->path, O_RDONLY);
    if (fd == -1)
        return (objerror(2));
    fill_fake_value(obj);
    while (get_next_line(fd, &line))
    {
        printf("%s\n", line);
        if (line[0] == 'f')
            fonction_face(obj);
        free(line);
    }
    free(line);
    return (0);
}