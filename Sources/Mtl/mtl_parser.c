/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtl_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <lomasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 14:25:00 by lomasse           #+#    #+#             */
/*   Updated: 2020/08/16 17:50:04 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MtlReader.h"
#include <stdio.h>

void            initmtl(t_mainmtl *mainmtl)
{
    mainmtl->parse[0] = name;
    mainmtl->parse[1] = Ns;
    mainmtl->parse[2] = Ka;
    mainmtl->parse[3] = Kd;
    mainmtl->parse[4] = Ks;
    mainmtl->parse[5] = Ke;
    mainmtl->parse[6] = Ni;
    mainmtl->parse[7] = d;
    mainmtl->parse[8] = illum;
    mainmtl->parse[9] = map_Kd;
}

void            parsing(char **line, t_mainmtl mainmtl, t_material **mat)
{
    if (!(ft_strncmp(*line, "newmtl\0", 6)))
    {
        name(*line, *mat); // Create New material
        if ((*mat)->next != NULL)
            (*mat) = (*mat)->next;
    }
    else if (!(ft_strncmp(*line, "Ns\0", 2)))
        Ns(*line, (*mat));
    else if (!(ft_strncmp(*line, "Ka\0", 2)))
        Ka(*line, (*mat));
    else if (!(ft_strncmp(*line, "Kd\0", 2)))
        Kd(*line, (*mat));
    else if (!(ft_strncmp(*line, "Ks\0", 2)))
        Ks(*line, (*mat));
    else if (!(ft_strncmp(*line, "Ke\0", 2)))
        Ke(*line, (*mat));
    else if (!(ft_strncmp(*line, "Ni\0", 2)))
        Ni(*line, (*mat));
    else if (!(ft_strncmp(*line, "d\0", 1)))
        d(*line, (*mat));
    else if (!(ft_strncmp(*line, "illum\0", 5)))
        illum(*line, (*mat));
    else if (!(ft_strncmp(*line, "map_Kd\0", 6)))
        map_Kd(*line, (*mat));
    else if (!(ft_strncmp(*line, "#\0", 1)))
        ;
    else if (!(ft_strncmp(*line, "\n\0", 1)))
        ;
    else if (!(ft_strncmp(*line, "\r\0", 1)))
        ;
    else if (!(ft_strncmp(*line, "\0\0", 1)))
        ;
    else
        printf("no find +> [%d]\n", (*line)[0]);
}

t_material      *mtlparser(char *path)
{
    t_material  *mat;
    t_material  *ptr;
    t_mainmtl   mainmtl;
    char        *buffer;
    int         fd;

    if (!(fd = open(path, O_RDONLY)) || fd == -1)
    {
        printf("MTL : File not found\n");
        return (NULL);
    }
    initmtl(&mainmtl);
    mat = malloc(sizeof(t_material));
    ptr = mat;
    mat->name = NULL;
    while (get_next_line(fd, &buffer))
    {
        parsing(&buffer, mainmtl, &mat);
        free(buffer);
    }
    free(buffer);
    mat = ptr;
    while (mat)
    {
        printf("Name : %s (id : %d)\n", mat->name, mat->id);
        printf("\t\tNs : %f\n", mat->Ns);
        printf("\t\tKa      : %f || %f || %f\n", mat->Ka.x, mat->Ka.y, mat->Ka.z);
        printf("\t\tKd      : %f || %f || %f\n", mat->Kd.x, mat->Kd.y, mat->Kd.z);
        printf("\t\tKs      : %f || %f || %f\n", mat->Ks.x, mat->Ks.y, mat->Ks.z);
        printf("\t\tKe      : %f || %f || %f\n", mat->Ke.x, mat->Ke.y, mat->Ke.z);
        printf("\t\tNi      : %f\n", mat->Ni);
        printf("\t\td       : %f\n", mat->d);
        printf("\t\tilum    : %d\n", mat->illum);
        printf("\t\tTexture : %s\n\n", mat->map_Kd);
        mat = mat->next;
    }
    free(path);
    return (ptr);
}