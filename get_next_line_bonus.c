/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analunga <analunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:36:56 by analunga          #+#    #+#             */
/*   Updated: 2024/05/21 03:25:24 by analunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_line_extractor(char *list)
{
	size_t	len;
	char	*str;
	size_t	i;

	if (!list || !*list)
		return (NULL);
	len = 0;
	while (list[len] && list[len] != '\n')
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1 + (list[len] == '\n')));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = list[i];
		i++;
	}
	if (list[len] == '\n')
	{
		str[i] = '\n';
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_store(char *remainder)
{
	t_store	store;

	if (!remainder)
		return (NULL);
	store.i = 0;
	while (remainder[store.i] && remainder[store.i] != '\n')
		store.i++;
	if (!remainder[store.i])
	{
		free(remainder);
		return (NULL);
	}
	store.len = ft_strlen(remainder) - store.i;
	store.new_remainder = (char *)malloc(sizeof(char) * (store.len + 1));
	if (!store.new_remainder)
		return (NULL);
	store.i++;
	store.j = 0;
	while (remainder[store.i])
		store.new_remainder[store.j++] = remainder[store.i++];
	store.new_remainder[store.j] = '\0';
	free(remainder);
	return (store.new_remainder);
}

static char	*ft_conjoin(int fd, char *remainder)
{
	t_conjoin	conjoin;

	conjoin.buff = malloc(BUFFER_SIZE + 1);
	if (fd < 0 || BUFFER_SIZE <= 0 || (!conjoin.buff))
		return (NULL);
	while (!ft_strchr(remainder, '\n'))
	{
		conjoin.read_bytes = read(fd, conjoin.buff, BUFFER_SIZE);
		if (conjoin.read_bytes == -1)
		{
			free(remainder);
			free(conjoin.buff);
			return (NULL);
		}
		if (conjoin.read_bytes == 0)
			break ;
		conjoin.buff[conjoin.read_bytes] = '\0';
		conjoin.temp = remainder;
		remainder = ft_strjoin(conjoin.temp, conjoin.buff);
		free(conjoin.temp);
		if (!remainder)
			break ;
	}
	free(conjoin.buff);
	return (remainder);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*remainder[MAX_FD + 1] = {0};

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	if (!remainder[fd])
		remainder[fd] = ft_strdup("");
	remainder[fd] = ft_conjoin(fd, remainder[fd]);
	if (!remainder[fd])
		return (NULL);
	line = ft_line_extractor(remainder[fd]);
	if (!line)
	{
		free(remainder[fd]);
		remainder[fd] = NULL;
		return (NULL);
	}
	remainder[fd] = ft_store(remainder[fd]);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("file.txt\n", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s\n", line);
// 		free(line);
// 	}
// 	if (line == NULL && errno != 0)
// 	{
// 		perror("Error reading file");
// 		close(fd);
// 		return (1);
// 	}
// 	if (close(fd) == -1)
// 	{
// 		perror("Error closing file");
// 		return (1);
// 	}
// 	return (0);
// }