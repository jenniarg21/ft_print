/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 13:29:31 by jargote           #+#    #+#             */
/*   Updated: 2016/11/13 13:46:40 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*node;
	t_list		*next;

	node = *alst;
	while (node != NULL)
	{
		next = node->next;
		(*del)(node->content, node->content_size);
		free(node);
		node = next;
	}
	*alst = NULL;
}
