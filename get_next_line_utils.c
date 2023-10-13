/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anados-s <anados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:16:18 by anados-s          #+#    #+#             */
/*   Updated: 2023/10/13 19:55:25 by anados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i + (str[i] == '\n'));
}

char	*found_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *line, char *buffer)
{
	char	*new;
	size_t	size; 
	int		i;
	int		j;

	i = 0;
	j = 0;
	size = ft_strlen(line) + ft_strlen(buffer);
	new = (char *)malloc(sizeof(char) * (size + 1));
	if (!new)
		return (manage_errors(line, buffer));
	while (line && line[i] != '\0')
	{
		new[i] = line [i];
		i++;
	}
	while (buffer[j] != '\0' && buffer[j] != '\n')
		new[i++] = buffer[j++];
	if (buffer[j] == '\n')
		new[i++] = '\n';
	new[i] = '\0';
	if (line)
		free(line);
	reorganizar_buffer(buffer);
	return (new);
}

char	*manage_errors(char *line, char *buffer)
{
	ssize_t		bytes_read;

	bytes_read = -1;
	while (buffer[++bytes_read])
		buffer[bytes_read] = 0;
	if (line)
		free(line);
	line = NULL;
	return (NULL);
}

char	*reorganizar_buffer(char *buffer)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(buffer);
	j = 0;
	while (buffer[i] != '\0')
	{
		buffer[j] = buffer[i];
		j++;
		i++;
	}
	while (buffer[j] != '\0')
	{
		buffer[j] = '\0';
		j++;
	}
	return (buffer);
}
