/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 22:46:13 by jargote           #+#    #+#             */
/*   Updated: 2017/01/23 19:16:17 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32
# define DELIMITER '\n'

# include "./libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct				s_file_content
{
	char					*content;
	int						fd;
	struct s_file_content	*next;
}							t_file_content;

int							get_next_line(const int fd, char **line);

#endif
