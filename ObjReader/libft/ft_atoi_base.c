/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 19:07:58 by luwargni          #+#    #+#             */
/*   Updated: 2020/01/19 21:05:40 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ispace(char *c)
{
	while (c)
	{
		if (*c == ' ' || *c == 8 || *c == 13)
			c++;
		else
			break ;
	}
	return (0);
}

int			ft_atoi_base(char *s, int b)
{
	int		i;
	int		j;
	int		nb[2];
	char	*hex_str;

	i = -1;
	*((long int*)(nb)) = 0;
	hex_str = "0123456789ABCDEF";
	if (!(b >= 2 && b <= 16))
		return (0);
	ft_ispace(s);
	s[i + 1] == '-' ? nb[1] = 1 : 0;
	s[i + 1] == '-' ? i++ : 0;
	if (s[i + 1] == '0' && s[i + 2] == 'x')
		i = i + 2;
	while (s[++i])
	{
		j = 0;
		if (s[i] != hex_str[j] && s[i] != (hex_str[j] + 32) && j < b)
			while (s[i] != hex_str[j] && s[i] != (hex_str[j] + 32) && j < b)
				j++;
		if (s[i] == hex_str[j] || s[i] == (hex_str[j] + 32))
			(*nb) = ((*nb) * b) + j;
	}
	return (nb[1] ? ~(*nb) + 1 : *nb);
}
