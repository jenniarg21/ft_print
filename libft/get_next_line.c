/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 22:45:06 by jargote           #+#    #+#             */
/*   Updated: 2017/01/16 14:17:30 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		find_new_line(t_file_content **file_c, char **line)
{
	int				line_size;
	t_file_content	*fc;
	char			*t_str;

	fc = *file_c;
	line_size = ft_memchrlen(fc->content, DELIMITER, ft_strlen(fc->content));
	if (line_size == 0)
		*line = ft_strnew(1);
	else
	{
		if (!(*line = ft_strsub(fc->content, 0, line_size)))
			return (-1);
	}
	if (!(t_str = ft_strsub(fc->content, (line_size + 1),
					ft_strlen(fc->content) - line_size)))
		return (-1);
	else
	{
		free(fc->content);
		fc->content = t_str;
	}
	*file_c = fc;
	return (1);
}

int		init_file_content(t_file_content **f, t_file_content **head, int fd)
{
	t_file_content	*t;
	t_file_content	*fc;

	t = *head;
	fc = *f;
	if (t == NULL || fc == NULL)
	{
		if (!(fc = (t_file_content *)malloc(sizeof(t_file_content))))
			return (0);
		fc->fd = fd;
		if (!(fc->content = (char *)malloc(BUFF_SIZE)))
			return (0);
		ft_bzero(fc->content, BUFF_SIZE);
		fc->next = NULL;
		if (*head == NULL)
			*head = fc;
		else
		{
			while (t->next)
				t = t->next;
			t->next = fc;
		}
	}
	*f = fc;
	return (1);
}

void	free_fc(t_file_content **file_c, t_file_content **h)
{
	t_file_content	*fc;
	t_file_content	*head;

	fc = *file_c;
	head = *h;
	ft_strdel(&fc->content);
	fc->fd = 0;
	if (fc == head)
	{
		if (fc->next != NULL)
			head = fc->next;
		else
			head = NULL;
	}
	while (head != NULL && head->next != NULL && head->next != fc)
		head = head->next;
	if (head != NULL && head->next != NULL && head->next == fc)
		head->next = fc->next;
	fc->next = NULL;
	ft_memdel((void *)&fc);
	*file_c = fc;
	*h = head;
}

int		set_content(char **content, int fd, char **line)
{
	char	*t_str;
	char	buff[BUFF_SIZE + 1];
	int		ret;

	ret = 1;
	while (ret > 0)
	{
		if ((ret = read(fd, buff, BUFF_SIZE)) == -1)
			return (-1);
		buff[ret] = 0;
		if (!(t_str = ft_strjoin(*content, buff)))
			return (-1);
		free(*content);
		*content = t_str;
		if (ret == 0 && ft_strlen(*content) == 0)
		{
			*line = 0;
			return (0);
		}
		if (ft_memchr(buff, DELIMITER, BUFF_SIZE) != NULL)
			break ;
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_file_content		*head;
	t_file_content				*fc;
	int							set_status;

	if (fd < 0 || !line || fd > 2147483547)
		return (-1);
	fc = head;
	while (fc && fc->fd != fd)
		fc = fc->next;
	if (!(init_file_content(&fc, &head, fd)))
		return (-1);
	if (!fc->content || ft_memchr(fc->content, DELIMITER,
				ft_strlen(fc->content)) == NULL)
	{
		if ((set_status = set_content(&fc->content, fd, line)) != 1)
		{
			if (set_status == 0)
				free_fc(&fc, &head);
			return (set_status);
		}
	}
	return (find_new_line(&fc, line));
}
