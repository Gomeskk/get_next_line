/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 21:31:04 by joafaust          #+#    #+#             */
/*   Updated: 2024/06/05 15:40:26 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	buff[BUFFER_SIZE + 1];
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE < 1)
	{
		while (buff[i])
			buff[i++] = 0;
		return (NULL);
	}
	line = NULL;
	while (*buff || read(fd, buff, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buff);
		if (nl(buff) == 1)
			break ;
	}
	return (line);
}

/* int	main(void)
{
	FILE *file;
	char *line;

	file = fopen("test1.txt", "r");
	if (!file)
	{
		perror("Error opening file");
		return (1);
	}
	while ((line = get_next_line(fileno(file))) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("BUFFER SIZE: %i\n", BUFFER_SIZE);
	fclose(file);
	return (0);
} */