/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ObjReader.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <lomasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 20:17:18 by lomasse           #+#    #+#             */
/*   Updated: 2020/08/09 19:45:20 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJREADER_H
# define OBJREADER_H
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../Includes/ObjError.h"
# include "../libft/get_next_line.h"

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
	unsigned int		flag;
}						t_face;

typedef struct          s_obj
{
	int					id;
	int					sub_id;
	long int			line;
	char				*path;
	long int			size_v[2];
	long int			size_vt[2];
	long int			size_vn[2];
	long int			size_vp[2];
	long int			size_face[2];
	t_face				*face;
	t_vertex4			*v;
	t_vertex			*vt;
	t_vertex			*vn;
	t_vertex			*vp;
	t_vertex			min;
	t_vertex			max;
	t_vertex			center;
	struct s_obj        *next;
}                       t_obj;

/*
**	Parsing
*/

char        			*skip_whitespace(char *str);
char      				*skip_whitespace(char *str);
void       				*realloc_vertex(t_obj *obj, char type, void **dest);
int       				fill_vertex(t_obj *obj, char *line, char type);
int       				find_next(char *line, int i);
int       				parsing_face(t_obj *obj, char *line);
int      				parsing_vertex(t_obj *obj, char *line);
int       				main_parser(t_obj *obj);

/*
**	Initialize
*/

int         			objload(char *path);
int         			objerror(t_obj *obj, int code);
t_obj       			*getobj(t_obj *obj);
int						init_obj(t_obj *obj);

#endif