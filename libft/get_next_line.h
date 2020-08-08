/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <lomasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 22:40:22 by luwargni          #+#    #+#             */
/*   Updated: 2020/01/20 17:38:30 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 500

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"

typedef struct		s_gnl
{
	size_t			fd;
	size_t			find;
	char			tmp[BUFF_SIZE];
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line(const int fd, char **line);

#endif
