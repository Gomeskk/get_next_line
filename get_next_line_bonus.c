/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 21:30:46 by joafaust          #+#    #+#             */
/*   Updated: 2024/06/05 10:19:40 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	buff[FOPEN_MAX][BUFFER_SIZE + 1];
	int			i;

	i = 0;
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1 || fd >= FOPEN_MAX)
	{
		if (fd > 0 && fd < FOPEN_MAX)
			while (buff[fd][i])
				buff[fd][i++] = 0;
		return (NULL);
	}
	line = NULL;
	while (*(buff[fd]) || read(fd, buff[fd], BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buff[fd]);
		if (nl(buff[fd]) == 1)
			break ;
	}
	return (line);
}
