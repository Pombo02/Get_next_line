/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anados-s <anados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:16:01 by anados-s          #+#    #+#             */
/*   Updated: 2023/10/13 20:11:05 by anados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytes_read;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX || \
		read(fd, &buffer, 0) < 0)
		return (manage_errors(line, buffer));
	bytes_read = 1;
	while (bytes_read > 0)
	{
		if (!buffer[0])
			bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (manage_errors(line, buffer));
		while (!found_newline(line) && buffer[0])
			line = ft_strjoin(line, buffer);
		if (found_newline(line)) 
			bytes_read = -1;
	}
	return (line);
}
