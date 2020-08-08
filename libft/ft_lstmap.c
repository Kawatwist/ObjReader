/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 22:35:16 by luwargni          #+#    #+#             */
/*   Updated: 2020/01/19 22:35:16 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*next;

	if (!lst)
		return (NULL);
	tmp = f(lst);
	if (!(next = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	lst = lst->next;
	new = next;
	while (lst)
	{
		tmp = f(lst);
		if (!(next->next = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		lst = lst->next;
		next = next->next;
	}
	return (new);
}
