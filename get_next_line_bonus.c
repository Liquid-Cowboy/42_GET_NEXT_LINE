/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnogueir <mnogueir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:45:23 by mnogueir          #+#    #+#             */
/*   Updated: 2025/10/27 17:21:02 by mnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

char	*get_next(char *buffer)
{
	char	*temp;
	int		i;
	int		j;

	if (!buffer || !buffer[0] || !ft_strchr((const char *)buffer, '\n'))
	{
		free(buffer);
		return (NULL);
	}
	i = 0;
	while (buffer[i] != '\n')
		i++;
	i++;
	temp = malloc((ft_strlen((char const *)buffer) - i) + 1);
	if (!temp)
		return (NULL);
	j = 0;
	while (buffer[i])
		temp[j++] = buffer[i++];
	temp[j] = '\0';
	free(buffer);
	return (temp);
}

char	*new_line(char *buffer)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	if (!buffer || !buffer[0])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	dest = malloc (i + 2);
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		dest[j++] = buffer[i++];
	if (buffer[i] == '\n')
		dest[j++] = '\n';
	dest[j] = '\0';
	return (dest);
}

char	*free_join(char *buffer, char *temp_buf)
{
	char	*temp;

	temp = ft_strjoin((char const *)buffer, (char const *)temp_buf);
	free (buffer);
	return (temp);
}

char	*read_buf(char *buffer, int fd)
{
	char	*temp_buf;
	int		bytes_read;

	bytes_read = 1;
	temp_buf = malloc(BUFFER_SIZE + 1);
	if (!temp_buf)
		return (NULL);
	while (bytes_read && !ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, temp_buf, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(temp_buf);
			free(buffer);
			buffer = NULL;
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		temp_buf[bytes_read] = '\0';
		buffer = free_join(buffer, temp_buf);
	}
	free(temp_buf);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD];
	char		*dest;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = ft_strdup("");
	buffer[fd] = read_buf(buffer[fd], fd);
	if (!buffer[fd])
		return (NULL);
	dest = new_line(buffer[fd]);
	buffer[fd] = get_next(buffer[fd]);
	return (dest);
}
