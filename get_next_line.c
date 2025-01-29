/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <doji@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:05:55 by doji              #+#    #+#             */
/*   Updated: 2025/01/29 19:06:01 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_new_left_str(char *left_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
	{
		free(left_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(left_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (left_str[i])
		str[j++] = left_str[i++];
	str[j] = '\0';
	free(left_str);
	return (str);
}

static char	*initialize_left_str(char *left_str, char **buf)
{
	*buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!*buf)
		return (NULL);
	if (!left_str)
		left_str = ft_strdup("");
	if (!left_str)
	{
		free(*buf);
		return (NULL);
	}
	return (left_str);
}

static char	*read_and_append(int fd, char *left_str, char *buf, int *read_size)
{
	char	*tmp;

	*read_size = read(fd, buf, BUFFER_SIZE);
	if (*read_size == -1)
	{
		free(buf);
		free(left_str);
		return (NULL);
	}
	buf[*read_size] = '\0';
	tmp = ft_strjoin(left_str, buf);
	free(left_str);
	if (!tmp)
	{
		free(buf);
		return (NULL);
	}
	return (tmp);
}

static char	*ft_read_to_left_str(int fd, char *left_str)
{
	char	*buf;
	int		read_size;

	buf = NULL;
	left_str = initialize_left_str(left_str, &buf);
	if (!left_str)
		return (NULL);
	read_size = 1;
	while (!ft_strchr(left_str, '\n') && read_size != 0)
	{
		left_str = read_and_append(fd, left_str, buf, &read_size);
		if (!left_str)
		{
			free(buf);
			return (NULL);
		}
	}
	free(buf);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str[4096];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 4096)
		return (NULL);
	left_str[fd] = ft_read_to_left_str(fd, left_str[fd]);
	if (!left_str[fd])
	{
		left_str[fd] = NULL;
		return (NULL);
	}
	line = ft_get_line(left_str[fd]);
	if (!line)
	{
		free(left_str[fd]);
		left_str[fd] = NULL;
		return (NULL);
	}
	left_str[fd] = ft_new_left_str(left_str[fd]);
	return (line);
}
