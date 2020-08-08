/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 22:40:18 by luwargni          #+#    #+#             */
/*   Updated: 2020/01/19 22:40:18 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_strdupfree(char **str)
{
	char *new;

	new = ft_strdup(ft_strchr(*str, '\n') + 1);
	free(*str);
	return (new);
}

static int		ft_strlenchr(char *str, char c)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != c && str[i])
		i++;
	return (i);
}

static char		*ft_makeline(char **line, char *content, char *ret, size_t nb)
{
	size_t	i;

	i = 0;
	if (!nb && !content)
		return (*line = NULL);
	if (content)
		content = ft_strjoinfree(content, ret, 1);
	else if (nb)
		content = ft_strdup(ret);
	i = ft_strlenchr(content, '\n');
	*line = ft_memalloc(i + 1);
	*line = ft_strncpy(*line, content, i);
	if (ft_strchr(content, '\n') && ft_strlen(ft_strchr(content, '\n') + 1))
		content = ft_strdupfree(&content);
	else
	{
		if (content)
			free(content);
		return (NULL);
	}
	return (content);
}

static t_list	*ft_findfd(const int fd, t_list **lst)
{
	t_list		*new;
	size_t		fd1;

	fd1 = (size_t)fd;
	if (!(*lst))
	{
		if (!((*lst) = ft_memalloc(sizeof(t_list))))
			return (NULL);
		(*lst)->content_size = fd1;
	}
	new = *lst;
	while (new->content_size != fd1 && new->next != NULL)
		new = new->next;
	if (new->content_size != fd1 && new->next == NULL)
	{
		if (!(new->next = ft_memalloc(sizeof(t_list))))
			return (NULL);
		new->next->content_size = fd1;
		new = new->next;
	}
	return (new);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*lst = NULL;
	t_list			*ct;
	char			ret[BUFF_SIZE + 1];
	size_t			nb;

	if (read(fd, &ret, 0) < 0 || fd == -1 || !(ct = ft_findfd(fd, &lst)))
		return (-1);
	while ((nb = read(fd, &ret, BUFF_SIZE)) > 0)
	{
		ret[nb] = '\0';
		if (ft_strchr(ret, '\n') != NULL)
		{
			ct->content = ft_makeline(line, ct->content, ret, nb);
			return (1);
		}
		ct->content ? (ct->content = ft_strjoinfree(ct->content, ret, 1)) :
			(ct->content = ft_strdup(ret));
	}
	ret[nb] = '\0';
	ct->content = ft_makeline(line, ct->content, ret, nb);
	if (*line != NULL)
		return (1);
	return (0);
}
