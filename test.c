#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

#define BUFFER_SIZE 42


int	main()
{
/*	char	buf[BUFFER_SIZE];
	int	chars_read;

	while ((chars_read = read(0, buf, BUFFER_SIZE)))
	{
		buf[chars_read] = '\0';
		printf("%s", buf);
	}
	return (0);*/

	char *src = "Hello World";
	char dest[100];

	printf("%zu\n", ft_strlen(src));
	printf("%s", ft_strjoin(dest, src));
	return (0);
}
