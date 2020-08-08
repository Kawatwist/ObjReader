/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_vertex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <lomasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 22:08:52 by lomasse           #+#    #+#             */
/*   Updated: 2020/08/08 22:20:22 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ObjReader.h"
#include "../../Includes/ObjError.h"

char    find_type(char  *line)
{
    if (line[1] == ' ' || line[1] == '\t' || line[1] == '\f')
        return (0);
    else if (line[1] == 't')
        return (1);
    else if (line[1] == 'n')
        return (2);
    else if (line[1] == 'p')
        return (3);
    return (-1);
}

int     parsing_vertex(t_obj *obj, char *line)
{
    char    type;
    type = find_type(line);
    return (0);
}