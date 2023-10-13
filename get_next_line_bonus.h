/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anados-s <anados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:11:45 by anados-s          #+#    #+#             */
/*   Updated: 2023/10/13 21:49:25 by anados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <stdlib.h>
# include <stdint.h>

char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
char	*found_newline(char *str);
char	*ft_strjoin(char *line, char *buffer, int fd);
char	*reorganizar_buffer(char *buffer);
char	*manage_errors(char *line, char *buffer, int fd);

#endif