/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 17:44:17 by jargote           #+#    #+#             */
/*   Updated: 2017/02/02 16:40:34 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*node;

	if (!(node = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!(node->content = (void *)malloc(sizeof(void) * content_size)))
	{
		free(node);
		return (NULL);
	}
	if (content == NULL || content_size == 0)
	{
		node->content = NULL;
		node->content_size = 0;
		node->next = NULL;
	}
	else
	{
	//	ft_bzero(node->content, content_size);
		node->content = ft_memcpy(node->content, content, content_size);
		node->content_size = content_size;
		node->next = NULL;
	}
	return (node);
}
