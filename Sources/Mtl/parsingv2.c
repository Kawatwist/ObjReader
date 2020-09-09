/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingv2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <lomasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 15:08:27 by lomasse           #+#    #+#             */
/*   Updated: 2020/08/16 15:35:39 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MtlReader.h"

void					Ke(char *line, t_material *ptr)
{
    ptr->Ke.x = atof(&(line[2])); // Atof
    ptr->Ke.y = atof(&(line[5])); // Atof
    ptr->Ke.z = atof(&(line[8])); // Atof
}

void					Ni(char *line, t_material *ptr)
{

    ptr->Ni = atof(&(line[2])); // Atof
}

void					d(char *line, t_material *ptr)
{
    ptr->d = atof(&(line[2])); // Atof
}

void					illum(char *line, t_material *ptr)
{
    ptr->illum = atoi(&(line[6])); // Atoi
}

void					map_Kd(char *line, t_material *ptr)
{
    ptr->map_Kd = ft_strdup(&(line[7]));
}
