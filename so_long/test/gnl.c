#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "gnl_h"
/*char *get_next_line(int fd)
{
    int     i = 0;
    int     rd;
    char    character;
    char    *buffer = malloc(10000);
    if (fd < 0 || BUFFER_SIZE <= 0)
	    return (free(buffer), NULL);
    while ((rd = read(fd, &character, 1)) > 0)
    {
        buffer[i++] = character;
        if (character == '\n')
            break;
    }
    if ((!buffer[i - 1] && !rd) || rd == -1)
    {
        free(buffer);
        return (NULL);
    }
    buffer[i] =  '\0';
    return(buffer);
}
*/
char *get_next_line(int fd)
{
	int i=-1;
	char c;
	char *buf = malloc(10000);
	if (fd <0 || BUFFER_SIZE <=0)
		{
			free(buf);
			return 0;
		}
	int rd;
	while ((rd = read(fd, &c,1))>0)
	{
		buf[++i] = c;
		if (c=='\n')
			break;
	}
	if ((!buf[i-1]&&rd==0) || rd==-1)
	{
		free(buf);
		return(0);
	}
	buf[i] = '\0';
	return(buf);
}

int main()
{
	int fd = open("./text.txt", O_RDONLY);
	char*line=get_next_line(fd);
	printf("%s",line);
}