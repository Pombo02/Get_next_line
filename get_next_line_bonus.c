/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anados-s <anados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:10:32 by anados-s          #+#    #+#             */
/*   Updated: 2023/10/13 21:54:08 by anados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytes_read;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX || \
		read(fd, &buffer[fd], 0) < 0)
		return (manage_errors(line, buffer[fd], fd));
	bytes_read = 1;
	while (bytes_read > 0)
	{
		if (!buffer[fd][0])
			bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
		if (bytes_read < 0)
			return (manage_errors(line, buffer[fd], fd));
		while (!found_newline(line) && buffer[fd][0])
			line = ft_strjoin(line, buffer[fd], fd);
		if (found_newline(line)) 
			bytes_read = -1;
	}
	return (line);
}
