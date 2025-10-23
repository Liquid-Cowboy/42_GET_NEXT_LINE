#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

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

/*	char *src = "Hello World";
	char dest[100];

	printf("%zu\n", ft_strlen(src));
	printf("%s", ft_strjoin(dest, src));*/
	int fd;
	char	*str;

	fd = open("test", O_RDONLY);

	while ((str = get_next_line(fd))!= NULL)
	{
		printf("-->%s", str);
		free(str);
	}

	return (0);
}
