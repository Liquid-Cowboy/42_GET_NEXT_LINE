#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
	char	*str;

    int fd = open("empty", O_RDONLY);
    if (fd < 0) 
	{
		perror("open"); return 1;
	}
	while ((str = get_next_line(fd)))
	{
		printf("%s", str);
		free(str);
	}
    return 0;
}

