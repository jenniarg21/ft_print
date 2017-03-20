/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 23:43:21 by jargote           #+#    #+#             */
/*   Updated: 2016/11/16 20:58:29 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_strncount(char const *s, char c, unsigned char start)
{
	unsigned int	count;

	count = 0;
	while (s[start] != '\0' && s[start] != c)
	{
		count++;
		start++;
	}
	return (count);
}

static unsigned int	ft_setchars(char const *s, char *arr, unsigned int i,
		unsigned int count)
{
	unsigned int	k;

	k = 0;
	while (k < count && s[i] != '\0')
	{
		arr[k] = s[i];
		k++;
		i++;
	}
	arr[k] = '\0';
	return (i);
}

static int			ft_setstrings(char const *s, char c, char **arr)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	count;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count = ft_strncount(s, c, i);
			if (!(arr[j] = (char *)malloc(sizeof(char) * (count + 1))))
				return (0);
			i = ft_setchars(s, arr[j], i, count);
			j++;
		}
		else
			i++;
	}
	if (!(arr[j] = (char *)malloc(1)))
		return (0);
	arr[j] = NULL;
	return (1);
}

char				**ft_strsplit(char const *s, char c)
{
	unsigned int	count;
	unsigned int	i;
	char			**arr;

	if (!s)
		return (NULL);
	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	if (!(arr = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	if (ft_setstrings(s, c, arr) == 1)
		return (arr);
	else
	{
		free(arr);
		return (NULL);
	}
}
