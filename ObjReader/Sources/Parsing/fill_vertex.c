/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_vertex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <lomasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 23:04:39 by lomasse           #+#    #+#             */
/*   Updated: 2020/08/11 15:09:42 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ObjReader.h"

int         find_next(char *line, int i)
{
    while (line[i] && !ft_isspace(line[i]))
        i++;
    while (line[i] && ft_isspace(line[i]))
        i++;
    return (i);
}

static int		count_zero(const char *str)
{
	int		count;

	count = 0;
	while (str[count] && str[count] == '0')
		count++;
	return (count);
}

static double	check_sign(const char **nptr, int *flag)
{
	if (!(*nptr) || *(*nptr) == '\0')
		return (0.0);
	if (*(*nptr) == '-' || *(*nptr) == '+')
	{
		(*flag) = (*(*nptr) == '-' ? 16777216 : 0);
		(*nptr)++;
	}
	while ((*nptr)[(*flag) & 0xFF] && (((*nptr)[(*flag) & 0xFF] >= '0' &&
	(*nptr)[(*flag) & 0xFF] <= '9') || (*nptr)[(*flag) & 0xFF] == '.'))
		(*flag) += 1;
	if (!((*nptr)[(*flag) & 0xFF] == '\0' || ((*nptr)[(*flag) & 0xFF] == ' ')))
		return (0.0);
	return (1);
}

static void		get_nbr2(const char *nptr, double *nbr2,
long long tmp, int *flag)
{
	int			nb_0;

	(*nbr2) = (double)ft_atoi(&(nptr[((*flag) & 0xFF) + 1]));
	tmp = (*nbr2);
	while (tmp)
	{
		tmp /= 10;
		(*flag) += (1 << 8);
	}
	tmp = 1;
	while (((*flag) & 0xFF00))
	{
		tmp *= 10;
		(*flag) -= (1 << 8);
	}
	nb_0 = count_zero(&(nptr[((*flag) & 0xFF) + 1]));
	while (nb_0)
	{
		tmp *= 10;
		nb_0--;
	}
	(*nbr2) /= tmp;
}

static float		ft_atof2(const char *nptr)
{
	double		nbr;
	double		nbr2;
	int			flag;

	nbr2 = 0.0;
	flag = 0;
	if ((check_sign(&nptr, &flag)) != 1.0)
		return (0.0);
	else
	{
		nbr = (double)ft_atoi(nptr);
		flag -= (flag & 0xFF);
		while (nptr[flag & 0xFF] != '.' &&
		nptr[flag & 0xFF] != '\0' && nptr[flag & 0xFF] != ' ')
			flag += 1;
		if ((flag & 0xFF) != 0 && nptr[flag & 0xFF] == '.')
			get_nbr2(nptr, &nbr2, 0, &flag);
	}
	nbr = nbr + nbr2;
	if (flag & 0x1000000)
		nbr *= -1;
	return ((float)nbr);
}


static int         str_tov4(t_vertex4 *dest, char *line)
{
    int i;

    i = 0;
    i = find_next(line, i);
    if (!line[i])
        return (1);
    dest->x = ft_atof2(&(line[i]));
    i = find_next(line, i);
    if (!line[i])
        return (1);
    dest->y = ft_atof2(&(line[i]));
    i = find_next(line, i);
    if (!line[i])
        return (1);
    dest->z = ft_atof2(&(line[i]));
    i = find_next(line, i);
    if (!line[i])
        dest->w = 1;
    else
        dest->w = ft_atof2(&(line[i]));
    return (0);
}

static void        set_v4to_v3(t_vertex *dest, t_vertex4 src)
{
    dest->x = src.x;
    dest->y = src.y;
    dest->z = src.z;
}

static int         fill_v4(t_obj *obj, t_vertex4 *v, char *line)
{
    if (str_tov4(&obj->v[obj->size_v[0]], line))
        return (1);
    if (!obj->size_v[0])
    {
        set_v4to_v3(&obj->min, obj->v[0]);
        set_v4to_v3(&obj->max, obj->v[0]);
    }
    else
    {
        obj->min.x > obj->v[obj->size_v[0]].x ? obj->min.x = obj->v[obj->size_v[0]].x : 0;
        obj->min.y > obj->v[obj->size_v[0]].y ? obj->min.y = obj->v[obj->size_v[0]].y : 0;
        obj->min.z > obj->v[obj->size_v[0]].z ? obj->min.z = obj->v[obj->size_v[0]].z : 0;
        obj->max.x < obj->v[obj->size_v[0]].x ? obj->max.x = obj->v[obj->size_v[0]].x : 0;
        obj->max.y < obj->v[obj->size_v[0]].y ? obj->max.y = obj->v[obj->size_v[0]].y : 0;
        obj->max.z < obj->v[obj->size_v[0]].z ? obj->max.z = obj->v[obj->size_v[0]].z : 0;
    }
   return (0);
}

static int         fill_v3(t_obj *obj, t_vertex *dest, char *line)
{
    int i;

    i = 0;
    i = find_next(line, i);
    if (!line[i])
        return (1);
    dest->x = ft_atof2(&(line[i]));
    i = find_next(line, i);
    if (!line[i])
        return (1);
    dest->y = ft_atof2(&(line[i - 1]));
    i = find_next(line, i);
    dest->z = ft_atof2(&(line[i]));
    return (0);
}

int         fill_vertex(t_obj *obj, char *line, char type)
{
    if (!type)
    {
        if (fill_v4(obj, &obj->v[obj->size_v[0]], line))
            return (1);
    }
    else if (type == 1)
    {
        if (fill_v3(obj, &obj->vt[obj->size_vt[0]], line))
            return (1);
    }
    else if (type == 2)
    {
        if (fill_v3(obj, &obj->vn[obj->size_vn[0]], line))
            return (1);
    }
    else if (type == 3)
    {
        if (fill_v3(obj, &obj->vp[obj->size_vp[0]], line))
            return (1);
    }
    else
        return (4);
    return (0);
}