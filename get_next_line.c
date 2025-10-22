#include "get_next_line.h"

char	*new_line(int fd, char *buffer)
{
	int	bytes_read;
	int	i;
	char	*temp_buf;



	bytes_read = 1;
	while (bytes_read)
	{	
		i = 0;
		bytes_read = read (fd, temp_buf, BUFFER_SIZE);
		temp_buf[bytes_read] = '\0';
		while (temp_buf[i] && temp_buf[i] != '\n')
			i++;
		if (ft_strchr((const char *)temp_buf, (int)'\n'))



	}
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char	*dest;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!buffer)
		buffer = NULL;

	return (dest);
}
