/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ObjReader.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <lomasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 20:17:18 by lomasse           #+#    #+#             */
/*   Updated: 2020/08/08 22:14:23 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJREADER_H
# define OBJREADER_H
# include <stdio.h>

typedef struct			s_vertex4
{
	float				w;
	float				x;
	float				y;
	float				z;
}						t_vertex4;

typedef struct			s_vertex
{
	float				x;
	float				y;
	float				z;
}						t_vertex;

typedef	struct			s_face
{
	int					size;
	int					*i_v;
	int					*i_vt;
	int					*i_vn;
}						t_face;

typedef struct          s_obj
{
	int					id;
	int					sub_id;
	char				*path;
	int					size_v;
	int					size_vt;
	int					size_vn;
	int					size_vp;
	t_face				*face;
	t_vertex4			*v;
	t_vertex			*vt;
	t_vertex			*vn;
	t_vertex			*vp;
	struct s_obj        *next;
}                       t_obj;

/*
**	Parsing
*/

char        *skip_whitespace(char *str);

/*
**	Initialize
*/

int						init_obj(t_obj *obj);

#endif