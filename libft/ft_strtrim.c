/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:10:59 by jargote           #+#    #+#             */
/*   Updated: 2016/11/16 21:37:54 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_issimplewhitespace(char c)
{
	if (c == 32 || c == '\n' || c == '\t')
		return (1);
	else
		return (0);
}

char		*ft_strtrim(char const *s)
{
	char			*trim;
	size_t			len;
	size_t			start;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	start = 0;
	while (s[start] != '\0' && ft_issimplewhitespace(s[start]))
		start++;
	if (s[start] != '\0')
	{
		while (len > 0 && ft_issimplewhitespace(s[len - 1]))
			len--;
		if (!(trim = (char *)malloc((len - start) + 2)))
			return (NULL);
		trim = ft_strsub(s, start, (len - start));
		trim[(len - start)] = '\0';
		return (trim);
	}
	if (!(trim = (char *)malloc(1)))
		return (NULL);
	trim[0] = '\0';
	return (trim);
}
