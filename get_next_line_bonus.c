/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 21:30:46 by joafaust          #+#    #+#             */
/*   Updated: 2024/06/05 12:06:32 by joafaust         ###   ########.fr       */
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

/*int main()
{
	int fd[3];

	fd[0] = open("test1.txt", O_RDONLY);
	fd[2] = open("test3.txt", O_RDONLY);
	fd[1] = open("test2.txt", O_RDONLY);
	char *test1 = get_next_line(fd[0]);
	char *test2 = get_next_line(fd[1]);
	char *test3 = get_next_line(fd[2]);
	while(test1 || test2 || test3)
	{
		printf("test1: %s\n", test1);
		printf("test2: %s\n", test2);
		printf("test3: %s\n", test3);
		test1 = get_next_line(fd[0]);
		test2 = get_next_line(fd[1]);
		test3 = get_next_line(fd[2]);
	}
	free(test1);
	free(test2);
	free(test3);

	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
}*/