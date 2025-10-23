#include "get_next_line.h"

char	*get_next(char *buffer)
{

}

char	*new_line(char *buffer)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
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
	int	bytes_read;

	bytes_read = 1;
	temp_buf = malloc(BUFFER_SIZE + 1);
	(!temp_buf)
		return (NULL);
	while (bytes_read)
	{
		bytes_read = read(fd, temp_buf, BUFFER_SIZE);
		if (bytes_read =< 0)
			break ;
		temp_buf[bytes_read] = '\0';
		buffer = free_join(buffer, temp_buf);
	}
	free(temp_buf);
	return (buffer);
}


char	get_next_line(int fd)
{
	static char	*buffer;
	char	*dest;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!buffer)
		buffer = NULL;
	buffer = read_buf(buffer, fd);
	dest = new_line(buffer);
	buffer = get_next(buffer);
	return (dest);
}
