/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MtlReader.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <lomasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 14:18:45 by lomasse           #+#    #+#             */
/*   Updated: 2020/08/16 15:44:02 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MTLREADER_H
# define MTLREADER_H

#include <stdlib.h>
#include <fcntl.h>
#include "../libft/libft.h"
#include "../libft/get_next_line.h"

typedef struct			s_value
{
	float				x;
	float				y;
	float				z;
}						t_value;

typedef struct 			s_material
{
	int					id;
	char				*name;

	float				Ns;
	t_value				Ka;
	t_value				Kd;
	t_value				Ks;
	t_value				Ke;
	float				Ni;
	float				d;
	char				illum;
	char				*map_Kd;
	struct s_material 	*next;
}               		t_material;

typedef	struct			s_mainmtl
{
	int					nb_material;
	void				(*parse[10]) (char *line, t_material *ptr);
}						t_mainmtl;

void					name(char *line, t_material *ptr);
void					Ns(char *line, t_material *ptr);
void					Ka(char *line, t_material *ptr);
void					Kd(char *line, t_material *ptr);
void					Ks(char *line, t_material *ptr);
void					Ke(char *line, t_material *ptr);
void					Ni(char *line, t_material *ptr);
void					d(char *line, t_material *ptr);
void					illum(char *line, t_material *ptr);
void					map_Kd(char *line, t_material *ptr);
t_material				*mtlparser(char *path);

# endif