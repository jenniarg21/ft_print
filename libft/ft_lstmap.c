/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 13:47:39 by jargote           #+#    #+#             */
/*   Updated: 2016/11/16 21:05:50 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*node;
	t_list	*prev;

	node = NULL;
	prev = NULL;
	if (lst)
	{
		if (!(node = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		if (!(node->content = (void *)malloc(sizeof(void) * lst->content_size)))
		{
			free(node);
			return (NULL);
		}
		node = (*f)(lst);
		if (lst != NULL)
		{
			lst = lst->next;
			prev = ft_lstmap(lst, (*f));
		}
		node->next = prev;
	}
	return (node);
}
