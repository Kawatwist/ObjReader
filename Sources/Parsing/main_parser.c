/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <lomasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 21:54:34 by lomasse           #+#    #+#             */
/*   Updated: 2020/08/16 15:27:03 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ObjReader.h"

static int            init_v_malloc(t_obj *obj)
{
	if (!(obj->group = malloc(sizeof(t_group))))
		return (1);
	obj->group->next = NULL;
	obj->group->size_face[0] = 0;
	obj->group->size_face[1] = 64;
	if (!(obj->group->face = malloc(sizeof(t_face) * 64)))
		return (1);
	obj->size_v[0] = 0;
	obj->size_v[1] = 64;
	if (!(obj->v = malloc(sizeof(t_vertex4) * 64)))
		return (1);
	ft_memset(obj->v, 0, sizeof(t_vertex4) * 64);
	obj->size_vn[0] = 0;
	obj->size_vn[1] = 64;
	if (!(obj->vn = malloc(sizeof(t_vertex) * 64)))
		return (1);
	ft_memset(obj->vn, 0, sizeof(t_vertex) * 64);
	obj->size_vt[0] = 0;
	obj->size_vt[1] = 64;
	if (!(obj->vt = malloc(sizeof(t_vertex) * 64)))
		return (1);
	ft_memset(obj->vt, 0, sizeof(t_vertex) * 64);
	obj->size_vp[0] = 0;
	obj->size_vp[1] = 64;
	if (!(obj->vp = malloc(sizeof(t_vertex) * 64)))
		return (1);
	ft_memset(obj->vp, 0, sizeof(t_vertex) * 64);
	return (0);
}

static int             adjust_allocation(t_obj *obj)
{
	void	*tmp;

	printf("Memory Management\n");
	tmp = obj->v;
	obj->v = NULL;
	if (!(obj->v = malloc(sizeof(t_vertex4) * obj->size_v[0])))
		return (1);
	ft_memcpy(obj->v, tmp, sizeof(t_vertex4) * obj->size_v[0]);
	obj->size_v[1] = obj->size_v[0];
	tmp = obj->vt;
	obj->vt = NULL;
	if (!(obj->vt = malloc(sizeof(t_vertex) * obj->size_vt[0])))
		return (1);
	ft_memcpy(obj->vt, tmp, sizeof(t_vertex) * obj->size_vt[0]);
	free(tmp);
	obj->size_vt[1] = obj->size_vt[0];
	tmp = obj->vn;
	obj->vn = NULL;
	if (!(obj->vn = malloc(sizeof(t_vertex) * obj->size_vn[0])))
		return (1);
	ft_memcpy(obj->vn, tmp, sizeof(t_vertex) * obj->size_vn[0]);
	free(tmp);
	obj->size_vn[1] = obj->size_vn[0];
	tmp = obj->vp;
	obj->vp = NULL;
	if (!(obj->vp = malloc(sizeof(t_vertex) * obj->size_vp[0])))
		return (1);
	ft_memcpy(obj->vp, tmp, sizeof(t_vertex) * obj->size_vp[0]);
	free(tmp);
	obj->size_vp[1] = obj->size_vp[0];
	printf("Memory Management Done\n");
	return (0);
}

void            fill_file(char **file, t_lst_buff *buffer, long int length)
{
	long unsigned int   pos;
	int                 i;
	void                *ptr;

	pos = 0;
	while (buffer != NULL)
	{
		i = -1;
		while (++i < 0b1111111111111110 && i < length)
		{
			(*file)[pos] = buffer->buff[i];
			pos += 1;
		}        
		length -= 0b1111111111111110;
		ptr = buffer;
		buffer = buffer->next;
		free(ptr);
	}
}

int			init_newgroup(t_group *ptr)
{
	ptr->material = NULL;
	ptr->size_face[0] = 0;
	ptr->size_face[1] = 64;
	if (!(ptr->face = malloc(sizeof(t_face) * 64)))
		return (1);
	return (0);
}

int             main_parser(t_obj *obj)
{
	char    *new;
	int     fd;
	int     error;

	fd = open(obj->path, O_RDONLY);
	if (fd == -1)
		return (objerror(obj, 2));
	if (init_v_malloc(obj))
		return (objerror(obj, 1));

/*           Reading File               */
	char        *file;
	long int    mem_size[2];
	size_t      reader;
	size_t      len_read;
	t_lst_buff  *buffer_lst;
	t_lst_buff  *lst;

	len_read = 0b1111111111111110;
	if (!(buffer_lst = malloc(sizeof(t_lst_buff))))
		return (1);
	reader = read(fd, buffer_lst->buff, len_read);
	if (reader == len_read + 1)
		printf("Reader error\n");
	mem_size[1] = reader;
	if (!(buffer_lst->next = malloc(sizeof(t_lst_buff))))
		return (1);
	lst = buffer_lst->next;
	while ((reader = (size_t)read(fd, lst->buff, len_read)) == len_read)
	{
		mem_size[1] += reader;
		if (!(lst->next = malloc(sizeof(t_lst_buff))))
			return (1);
		lst =lst->next;
	}
/*           Reading File               */
	lst->next = NULL;
	mem_size[1] += reader;
	printf("Memory size used : %ld\n", mem_size[1]);
	if (reader == len_read + 1)
		printf("Reader error -1\n");
	if (!(file = malloc(mem_size[1])))
		return (1);
	fill_file(&file, buffer_lst, mem_size[1]);
	
	char    *tmp;
	char    *line;
	t_group	*ptr;

	ptr = obj->group;
	line = file;
	tmp = line;
	obj->line = 0;
	mem_size[0] = mem_size[1];
	new = skip_whitespace(line, mem_size[0]);
	if (new == NULL)
		return (objerror(obj, 4));
	line = ft_memchr(new, '\n', mem_size[0]);
	line[0] = '\0';
	while (line && new && mem_size[0])
	{
		if (!(obj->line % 100000))
			printf("%% %d ==> %ld\n", (int)(100 - ((float)mem_size[0] / (float)mem_size[1]) * 100.0), mem_size[0]);
		if (new == NULL || !new[0])
			;
		else if (new[0] == 'v')
		{
			if ((error = parsing_vertex(obj, new)))
				return (objerror(obj, error));
		}
		else if (new[0] == 'f')
		{
			if ((error = parsing_face(obj, ptr, new)))
				return (objerror(obj, error));
		}
		else if (new[0] == '#')
			;
		else if (new[0] == 'o')
			;
		else if (new[0] == 'g')
		{
			if (ptr->size_face[0] > 0)
			{
				if (!(ptr->next = malloc(sizeof(t_group))))
					return (objerror(obj, 1));
				ptr = ptr->next;
				if ((error = init_newgroup(ptr)))
					return (objerror(obj, 1));
				printf("New group Create\n");
			}
		}
		else if (new[0] == 'm' || new[0] == 'u')
		{
			int size;
			size = ft_strlen(&(new[6]));
			if (new[0] == 'm')
				obj->mtlib = ft_strndup(skip_whitespace(&(new[6]), size), size);
			else
			{
				ptr->material = ft_strdup(skip_whitespace(&(new[6]), size));
				ptr->material[ft_strlen(ptr->material) - 1] = 0;
			}
		}
		else if (new[0] == 's')
			;
		else if (new[0] == '\r')
			;
		else
		{
			printf("Invalid char : %s\n", new);
			return (objerror(obj, 4));
		}
		line = ft_memchr(new, '\0', mem_size[0]);
		if (line == NULL)
			break ;
		line += 1;
		while (mem_size[0] && (line[0] == '\n' || line[0] == '\0'))
		{
			line++;
			mem_size[0] -= 1;
		}
		mem_size[0] -= line - tmp;
		if (mem_size[0] <= 0)
			break ;
		tmp = line;
		new = skip_whitespace(line, mem_size[0]);
		if (new == NULL)
			break ;
		line = ft_memchr(new, '\n', mem_size[0]);
		if (line != NULL)
			line[0] = '\0';
		else
			break ;
		obj->line++;
	}
	if (obj->flag & MEMORY)
	{
		if (adjust_allocation(obj))
			return (1);
	}
	free(file);
	obj->center.x = (obj->min.x + obj->max.x / 2.0);
	obj->center.y = (obj->min.y + obj->max.y / 2.0);
	obj->center.z = (obj->min.z + obj->max.z / 2.0);
	if (obj->flag & INFO)
	{
		printf("Min : %f\t\t%f\t\t%f\n", obj->min.x, obj->min.y, obj->min.z);
		printf("Max : %f\t\t%f\t\t%f\n", obj->max.x, obj->max.y, obj->max.z);
		printf("VtMin : %f\t\t%f\t\t%f\n", obj->vtmin.x, obj->vtmin.y, obj->vtmin.z); // useless ?
		printf("VtMax : %f\t\t%f\t\t%f\n", obj->vtmax.x, obj->vtmax.y, obj->vtmax.z);
		printf("Center : %f\t\t%f\t\t%f\n", obj->center.x, obj->center.y, obj->center.z);
		printf("Il y a :\n");
		printf("\t\t. %ld\t\t= v~\t\t%ld\t(Mallocated)\n", obj->size_v[0], obj->size_v[1]);
		printf("\t\t. %ld\t\t= vt\t\t%ld\t(Mallocated)\n", obj->size_vt[0], obj->size_vt[1]);
		printf("\t\t. %ld\t\t= vn\t\t%ld\t(Mallocated)\n", obj->size_vn[0], obj->size_vn[1]);
		printf("\t\t. %ld\t\t= vp\t\t%ld\t(Mallocated)\n", obj->size_vp[0], obj->size_vp[1]);
		t_group *ptr;
		int		i;
		int		j;

		i = 0;
		ptr = obj->group;
		while (ptr)
		{
			printf("\t\tGroup[%d] => . %ld\t\t= f~\t\t%ld\t(Mallocated)\n",i, ptr->size_face[0], ptr->size_face[1]);
			printf("\t\t\tMaterial : [%s]\n", ptr->material);
			printf("\t\t\tPath : [%s]\n", ptr->path);
			ptr = ptr->next;
			i++;
		}
		printf("Nb group : [%d]\nDone : %s\n", i, obj->path);
	}
	return (0);
}