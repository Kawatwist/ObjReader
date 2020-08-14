/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <lomasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 20:55:57 by lomasse           #+#    #+#             */
/*   Updated: 2020/08/14 16:51:46 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ObjReader.h"

int         main(int argc, char **argv)
{
    t_obj   *obj;

    if (!(obj = malloc(sizeof(t_obj))))
        return (objerror(NULL, 1));
    if (init_obj(obj) == -1)
        return (objerror(obj, -1));
    if (argc < 2 || argc > 2)
        return (objerror(obj, 2));
    objload(argv[1], INFO);
	// int i = -1;
	// while (++i < obj->size_v[0])
	// {
	// 	printf("%f || %f || %f\n", obj->v[i].x, obj->v[i].y, obj->v[i].z);
	// }
    return (0);
}