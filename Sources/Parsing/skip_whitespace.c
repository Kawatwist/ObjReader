/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_whitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <lomasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 22:10:28 by lomasse           #+#    #+#             */
/*   Updated: 2020/08/09 15:42:26 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ObjReader.h"
#include "../../Includes/ObjError.h"
#include "../../libft/get_next_line.h"
#include <fcntl.h>

char        *skip_whitespace(char *str)
{
    int     i;
    char    *ret;

    i = -1;
    while ((str[++i] == ' ' || str[i] == '\t'
        || str[i] == '\f') && str[i])
        ;
    if (!str[i])
        return (0x0);
    return (str + i);
}