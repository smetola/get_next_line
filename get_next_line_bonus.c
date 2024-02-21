/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanmetol <sanmetol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:51:48 by sanmetol          #+#    #+#             */
/*   Updated: 2024/02/21 19:53:41 by sanmetol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_rest(char *str)
{
	char	*rest;
	int		i;
	int		j;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	rest = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!rest)
		return (NULL);
	j = 0;
	while (str[i])
		rest[j++] = str[i++];
	rest[j] = '\0';
	free(str);
	return (rest);
}

char	*ft_get_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	line = malloc(sizeof(char) * i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_read(int fd, char *str)
{
	int		chars_read;
	char	*buf;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	chars_read = 1;
	while (!ft_strchr(str, '\n') && chars_read != 0)
	{
		chars_read = read(fd, buf, BUFFER_SIZE);
		if (chars_read == -1)
		{
			free(buf);
			free(str);
			return (NULL);
		}
		buf[chars_read] = '\0';
		str = ft_strjoin(str, buf);
	}
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*text[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	text[fd] = ft_read(fd, text[fd]);
	if (!text[fd])
		return (NULL);
	line = ft_get_line(text[fd]);
	text[fd] = get_rest(text[fd]);
	if (!line)
	{
		free(text[fd]);
		return (NULL);
	}
	return (line);
}

/* int	main(void)
{
	int		fd1, fd2, fd3;
	char	*line;

	fd1 = open("./GNL tests/OuterWilds1.txt", O_RDONLY);
	fd2 = open("./GNL tests/OuterWilds2.txt", O_RDONLY);
	fd3 = open("./GNL tests/OuterWilds3.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd1);
		if (line)
		{
			printf("fd1: %s\n", line);
			free(line);
		}
		line = get_next_line(fd2);
		if (line)
		{
			printf("fd2: %s\n", line);
			free(line);
		}
		line = get_next_line(fd3);
		if (line)
		{
			printf("fd3: %s\n", line);
			free(line);
		}
		if (!line)
			break;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	printf("\n\n");
	system("leaks -q a.out");
} */
